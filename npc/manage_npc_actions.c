/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void npc_gps(npc_t *npc)
{
    npc->pos_px = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc->pos_px.x / 32;
    npc->pos_cart.y = npc->pos_px.y / 32;
}

void manage_npc_actions(npc_t *npc, player_t *player)
{
    if (npc->index_action == 0 && action_move_npc(npc, player, 10, 4) == 1) {
        npc->index_action++;
    }
    if (npc->index_action == 1 && action_wait_npc(npc, player, 2) == 1) {
        npc->index_action++;
    }
    if (npc->index_action == 2 && action_move_npc(npc, player, 10, 2) == 1) {
        npc->index_action++;
    }
    if (npc->index_action == 3 && action_wait_npc(npc, player, 2) == 1) {
        npc->index_action = 0;
    }
}