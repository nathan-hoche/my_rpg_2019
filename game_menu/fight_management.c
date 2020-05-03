/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int start_fight(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    static int step = -1;

    if (step == -1) {
        game->on_msg = -1;
        step = 0;
    }
    step = manage_before_fight(game, general, npc, step);
    if (step == 2 && fight_controller(game, general, npc) == 1)
        step = 3;
    step = manage_after_fight(game, general, npc, step);
    return (1);
}

int fight_management(game_menu_t *game, csfml_t *general)
{
    if (game->on_fight == 0)
        return (0);
    else
        start_fight(game, general, &game->npc[game->on_fight - 1]);
    return (0);
}