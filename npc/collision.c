/*
** EPITECH PROJECT, 2020
** collision.c
** File description:
** collision
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int check_npc_collision(npc_t *npc, player_t *player)
{
    if ((npc->traj_cart.x == player->pos_cart.x && \
    npc->traj_cart.y == player->pos_cart.y) || \
    (npc->traj_cart.x == player->pos_cart.x) && \
    (npc->traj_cart.y - 1 == player->pos_cart.y))
        return (1);
    if ((npc->traj_cart.x == player->pos_cart.x && \
    npc->traj_cart.y == player->pos_cart.y - 1) || \
    (npc->traj_cart.x == player->pos_cart.x) && \
    (npc->traj_cart.y - 1 == player->pos_cart.y - 1))
        return (1);
    return (0);
}