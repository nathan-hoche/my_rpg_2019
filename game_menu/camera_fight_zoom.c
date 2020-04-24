/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage zoom when a fight is detected
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void camera_fight_zoom(game_menu_t *game, csfml_t *page)
{
    sfTime time;
    static int times = 0;
    static int state = 1;

    if (state == 1)
        game->cam_clock = sfClock_create();
    state = 2;
    time = sfClock_getElapsedTime(game->cam_clock);
    if (time.microseconds >= 100) {
        page->view = sfRenderWindow_getView(page->window);
        sfView_zoom(page->view, 0.99);
        sfRenderWindow_setView(page->window, page->view);
        times++;
    }
    if (times == 180) {
        times = 0;
        game->on_fight = 0;
        sfClock_destroy(game->cam_clock);
        state = 0;
    }
}