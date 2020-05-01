/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void camera_effects(csfml_t *general)
{
    sfView_zoom(general->views.actual_view, 0.98);
    sfView_rotate(general->views.actual_view, 0.14);
    sfRenderWindow_setView(general->window, general->views.actual_view);
}

static int camera_fight_zoom(game_menu_t *game, csfml_t *general)
{
    sfTime time;
    static int times[2] = {1, 0};

    if (times[0] == 1)
        game->cam_clock = sfClock_create();
    times[0] = 2;
    time = sfClock_getElapsedTime(game->cam_clock);
    if (time.microseconds >= 50) {
        camera_effects(general);
        times[1]++;
    }
    if (times[1] == 60) {
        times[1] = 0;
        times[0] = 1;
        game->on_fight = 0;
        sfClock_destroy(game->cam_clock);
        general->views.actual_view = \
            sfView_copy(general->views.default_player_view);
        return (1);
    }
    return (0);
}

void start_fight(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    game->on_fight = 0;
    if (camera_fight_zoom(game, general) == 1) {
        game->on_fight = 0;
        fight_core(general, game, npc);
    }
}