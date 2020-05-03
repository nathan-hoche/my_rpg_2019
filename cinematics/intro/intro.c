/*
** EPITECH PROJECT, 2020
** intro.c
** File description:
** intro
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

static void destroy_intro(intro_t *intro)
{
    sfTexture_destroy(intro->intro_tx);
    sfSprite_destroy(intro->intro_sp);
}

static int set_intro_effect(game_menu_t *game, sfColor color, int check)
{
    if (check >= 255) {
        color.a = 0;
        sfSprite_setColor(game->intro.intro_sp, color);
        destroy_intro(&game->intro);
        sfClock_destroy(game->cam_clock);
        return (0);
    }
    return (1);
}

void display_intro(sfRenderWindow *window, game_menu_t *game)
{
    sfTime time;
    static sfColor color = {0, 0, 0, 255};
    static int check = 0;
    static int flag = 0;

    if (flag == 0)
        game->cam_clock = sfClock_create();
    flag = 1;
    time = sfClock_getElapsedTime(game->cam_clock);
    sfRenderWindow_drawSprite(window, game->intro.intro_sp, NULL);
    if (time.microseconds >= 10000) {
        color.a = color.a - 1;
        check += 1;
        sfSprite_setColor(game->intro.intro_sp, color);
        flag = set_intro_effect(game, color, check);
        if (flag == 0) {
            game->intro.on_intro = 0;
            check = 0;
        } else
            sfClock_restart(game->cam_clock);
    }
}

void begin_cinematics(intro_t *intro, csfml_t *general, \
outro_t *outro)
{
    intro->on_intro = 1;
    intro->intro_tx = make_texture(INTRO_BACKGROUND);
    intro->intro_sp = make_sprite(intro->intro_tx);
    outro->outro_tx = make_texture(OUTRO_BACKGROUND);
    outro->memory_tx = make_texture(MEMORY_PIC);
    outro->ending_tx = make_texture(ENDING_PIC);
    outro->outro_sp = make_sprite(outro->outro_tx);
    outro->memory_sp = make_sprite(outro->memory_tx);
    outro->ending_sp = make_sprite(outro->ending_tx);
    sfRenderWindow_setView(general->window, general->views.default_view);
}