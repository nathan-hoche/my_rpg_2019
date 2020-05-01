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

void perform_npc_actions(npc_t *npc, player_t *player)
{
    static int index = 0;
    int param[2][2] = {{5, 2}, {5, 4}};

    if (index == 0 && move_npc(npc, player, 8, 2) == END_NPC_ACT)
        index++;
    if (index == 1 && move_npc(npc, player, 8, 4) == END_NPC_ACT)
        index++;
    if (index == 2)
        index = 0;
}