/*
** EPITECH PROJECT, 2020
** action_wait_npc.c
** File description:
** patern of action for npc 01
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int patern_npc_01(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    switch (npc->index_action) {
        case 0:
            if (action_move_npc(npc, &general->player, 5, 2) == 1)
                npc->index_action++;
            break;
        case 1:
            if (action_move_npc(npc, &general->player, 5, 3) == 1)
                npc->index_action++;
            break;
        case 2:
            if (action_move_npc(npc, &general->player, 5, 4) == 1)
                npc->index_action++;
            break;
        case 3:
            if (action_move_npc(npc, &general->player, 5, 1) == 1)
                npc->index_action = 0;
            break;
        default:
            break;
    }
}