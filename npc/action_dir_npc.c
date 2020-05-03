/*
** EPITECH PROJECT, 2020
** action_wait_npc.c
** File description:
** action to view on dir by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int action_dir_npc(npc_t *npc, player_t *player, int dir)
{
    if (npc->tx_rect.top != 128 && player->pos_cart.x > npc->pos_cart.x) {
        npc->tx_rect.top = 128;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    else if (npc->tx_rect.top != 64 && player->pos_cart.x < npc->pos_cart.x) {
        npc->tx_rect.top = 64;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    if (npc->tx_rect.top != 192 && player->pos_cart.y < npc->pos_cart.y) {
        npc->tx_rect.top = 192;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    else if (npc->tx_rect.top != 0 && player->pos_cart.y > npc->pos_cart.y) {
        npc->tx_rect.top = 0;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
}