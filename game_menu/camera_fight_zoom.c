/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage zoom when a fight is detected
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int camera_fight_zoom(game_menu_t *game, csfml_t *page)
{
    sfTime time;
    static int times[2] = {1, 0};

    if (times[0] == 1)
        game->cam_clock = sfClock_create();
    times[0] = 2;
    time = sfClock_getElapsedTime(game->cam_clock);
    if (time.microseconds >= 50) {
        sfView_zoom(page->views.actual_view, 0.98);
        sfRenderWindow_setView(page->window, page->views.actual_view);
        times[1]++;
    }
    if (times[1] == 60) {
        times[1] = 0;
        times[0] = 1;
        game->on_fight = 0;
        sfClock_destroy(game->cam_clock);
        page->views.actual_view = sfView_copy(page->views.default_player_view);
        return (1);
    }
    return (0);
}