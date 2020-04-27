/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void start_fight(game_menu_t *game, csfml_t *page)
{
    if (camera_fight_zoom(game, page) == 1) {
        game->on_fight = 0;
        fight_core(page, game);
    }
}
