/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int start_message(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    if (action_message(game->npc[1].talk_1, game) == 1)
        game->on_msg = 0;
    return (0);
}

int message_management(game_menu_t *game, csfml_t *general)
{
    if (game->inter == 1 && game->on_fight == 0 && game->on_msg != 0)
        start_message(game, general, &game->npc[game->on_fight - 1]);
    display_message_box(game, general);
    return (0);
}