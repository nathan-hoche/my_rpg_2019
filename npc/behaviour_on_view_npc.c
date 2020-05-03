/*
** EPITECH PROJECT, 2020
** behaviour_wait_npc.c
** File description:
** behaviour to see player on differents distances by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int behaviour_see_player_proximity(player_t *player, npc_t *npc, int dir, int dist)
{
    if (player->pos_cart.x == npc->pos_cart.x && 
    player->pos_cart.y >= npc->pos_cart.y - dist && player->pos_cart.y < npc->pos_cart.y)
        return (1);
/* 
    if (player->pos_cart.x <= npc->pos_cart.x && 
    player->pos_cart.y == npc->pos_cart.y - dist)
        return (1);

    if (player->pos_cart.x == npc->pos_cart.x && 
    player->pos_cart.y <= npc->pos_cart.y + dist)
        return (1); */
}