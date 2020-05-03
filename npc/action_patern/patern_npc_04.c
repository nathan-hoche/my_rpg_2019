/*
** EPITECH PROJECT, 2020
** action_wait_npc.c
** File description:
** patern of action for npc 01
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int patern_npc_04(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    static int move = 0;

    if (game->adventure_step == 2 && npc->is_fighter == 1 && \
    general->player.pos_cart.x >= npc->pos_cart.x - 3)
        action_npc_focus_player(&general->player, npc);
    if (move == 0 && npc->is_fighter == 0)
        if (action_move_npc(npc, &general->player, 3, 2))
            move = 1;
    return (0);
}