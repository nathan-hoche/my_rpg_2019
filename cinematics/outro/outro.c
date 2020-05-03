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
    sfTexture_destroy(outro->memory_tx);
    sfSprite_destroy(outro->memory_sp);
    sfTexture_destroy(outro->outro_tx);
    sfSprite_destroy(outro->outro_sp);
}

static int set_outro_effect(game_menu_t *game, sfColor color, int check)
{
    if (check >= 150) {
        color.a = 0;
        sfSprite_setColor(game->outro.memory_sp, color);
        destroy_outro(&game->outro);
        sfClock_destroy(game->cam_clock);
        return (0);
    }
    return (1);
}

static int display_memory(sfRenderWindow *window, outro_t *outro, \
sfColor color, int check)
{
    return (check);
}

void display_outro(sfRenderWindow *window, game_menu_t *game)
{
    sfTime time;
    static sfColor color = {0, 0, 0, 150};
    static int check = 0;
    static int flag = 0;

    if (flag == 0)
        game->cam_clock = sfClock_create();
    flag = 1;
    time = sfClock_getElapsedTime(game->cam_clock);
    sfSprite_setScale(game->outro.memory_sp, (sfVector2f) {1.6, 1.6});
    sfRenderWindow_drawSprite(window, game->outro.outro_sp, NULL);
    sfRenderWindow_drawSprite(window, game->outro.memory_sp, NULL);
    sfSprite_setColor(game->outro.memory_sp, color);
    if (time.microseconds >= 100) {
        color.a = color.a - 1;
        check = check + 1;
        sfSprite_setColor(game->outro.memory_sp, color);
        check = display_memory(window, &game->outro, color, check);
        flag = set_outro_effect(game, color, check);
        if (flag == 0) {
            game->outro.on_outro = 0;
            check = 0;
        } else
            sfClock_restart(game->cam_clock);
    }
}

void begin_outro(outro_t *outro)
{
    outro->outro_tx = make_texture(OUTRO_BACKGROUND);
    outro->memory_tx = make_texture(MEMORY_PIC);
    outro->outro_sp = make_sprite(outro->outro_tx);
    outro->memory_sp = make_sprite(outro->memory_tx);
    outro->on_outro = 1;
}