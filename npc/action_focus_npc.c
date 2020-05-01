/*
** EPITECH PROJECT, 2020
** action_wait_npc.c
** File description:
** action to focus player by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void action_npc_focus_player(player_t *player, npc_t *npc)
{
    if (player->pos_cart.x > npc->pos_cart.x) {
        npc->tx_rect.top = 128;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    else if (player->pos_cart.x < npc->pos_cart.x) {
        npc->tx_rect.top = 64;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    if (player->pos_cart.y < npc->pos_cart.y) {
        npc->tx_rect.top = 192;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    else if (player->pos_cart.y > npc->pos_cart.y) {
        npc->tx_rect.top = 0;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
}