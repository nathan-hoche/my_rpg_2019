/*
** EPITECH PROJECT, 2020
** outro.c
** File description:
** outro
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

static void destroy_outro(outro_t *outro)
{
    sfTexture_destroy(outro->outro_tx);
    sfSprite_destroy(outro->outro_sp);
    sfTexture_destroy(outro->memory_tx);
    sfSprite_destroy(outro->memory_sp);
}

static int set_outro_effect(game_menu_t *game, sfColor color, \
sfRenderWindow *window, int check)
{
    sfSprite_setColor(game->outro.memory_sp, color);
    if (check >= 18) {
        color.a = 180;
        sfSprite_setColor(game->outro.memory_sp, color);
        destroy_outro(&game->outro);
        sfClock_destroy(game->cam_clock);
        return (0);
    }
    return (1);
}

static int display_ending(sfRenderWindow *window, game_menu_t *game, int check)
{
    static int flag = 0;
    sfTime time;

    if (flag == 0)
        game->cam_clock = sfClock_create();
    flag = 1;
    time = sfClock_getElapsedTime(game->cam_clock);
    sfSprite_setScale(game->outro.ending_sp, (sfVector2f) {1.15, 1.13});
    if (time.microseconds >= 0) {
        sfRenderWindow_drawSprite(window, game->outro.ending_sp, NULL);
        sfRenderWindow_display(window);
        sfClock_destroy(game->cam_clock);
        game->outro.on_outro = 0;
        sfSleep((sfTime) {2000000});
        check = 0;
    }
    return (check);
}

void display_outro(sfRenderWindow *window, game_menu_t *game)
{
    sfTime time;
    static sfColor color = {0, 0, 0, 120};
    static int check = 0;
    static int flag = 0;

    if (flag == 0)
        game->cam_clock = sfClock_create();
    flag = 1;
    time = sfClock_getElapsedTime(game->cam_clock);
    set_outro(window, game);
    sfSprite_setColor(game->outro.memory_sp, color);
    if (time.microseconds >= 100) {
        color.a = color.a - 8;
        check += 1;
        flag = set_outro_effect(game, color, window, check);
        if (flag == 0)
            check = display_ending(window, game, check);
        else
            sfClock_restart(game->cam_clock);
    }
}

void begin_outro(csfml_t *general, outro_t *outro)
{
    outro->outro_tx = make_texture(OUTRO_BACKGROUND);
    outro->memory_tx = make_texture(MEMORY_PIC);
    outro->ending_tx = make_texture(ENDING_PIC);
    outro->outro_sp = make_sprite(outro->outro_tx);
    outro->memory_sp = make_sprite(outro->memory_tx);
    outro->ending_sp = make_sprite(outro->ending_tx);
    sfRenderWindow_setView(general->window, general->views.default_view);
}