/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void npc_dir(npc_t *npc)
{
    int dir_rect[4] = {192, 128, 0, 64};
    int i = 0;

    for (i = 0; npc->tx_rect.top != dir_rect[i]; i++);
    npc->dir = i + 1;
}

void npc_gps(npc_t *npc)
{
    npc->pos_px = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc->pos_px.x / 32;
    npc->pos_cart.y = npc->pos_px.y / 32;
    npc_dir(npc);
}

void manage_npc_actions(csfml_t *general, game_menu_t *game)
{
    if (game->on_msg != 0 || game->on_fight != 0)
        return;
    for (int i = 0; i < NB_NPC; i++)
        if (game->npc[i].state != 0 && game->npc[i].action_patern != NULL)
            game->npc[i].action_patern(game, general, &game->npc[i]);
}