/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

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
/* 
    if (move_npc(npc, param[index][0], param[index][1]) == END_NPC_ACT) {
        index++;
        if (index == 2)
            index = 0;
    } */
}