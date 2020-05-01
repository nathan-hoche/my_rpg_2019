/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void update_npc_pos(npc_t *npc, int dir)
{
    npc_gps(npc);
    switch (dir) {
        case 1:
            npc->traj_cart.x = npc->pos_cart.x;
            npc->traj_cart.y = npc->pos_cart.y - 1;
            break;
        case 2:
            npc->traj_cart.x = npc->pos_cart.x + 1;
            npc->traj_cart.y = npc->pos_cart.y;
            break;
        case 3:
            npc->traj_cart.x = npc->pos_cart.x;
            npc->traj_cart.y = npc->pos_cart.y + 1;
            break;
        case 4:
            npc->traj_cart.x = npc->pos_cart.x - 1;
            npc->traj_cart.y = npc->pos_cart.y;
            break;
        default:
            break;
    }
}

static int handle_npc_move(npc_t *npc, int dir, int dist)
{
    int local_dist = dist;
    int direction[4][2] = {{0, -4}, {4, 0}, {0, 4}, {-4, 0}};
    int dir_rect[4] = {192, 128, 0, 64};
    sfTime time = sfClock_getElapsedTime(npc->move);

    if (dist == 0) {
        npc->tx_rect.top = dir_rect[dir - 1];
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    }
    if (time.microseconds >= 25000) {
        sfSprite_move(npc->sp, (sfVector2f) \
            {direction[dir - 1][0], direction[dir - 1][1]});
        local_dist += 4;
        sfClock_restart(npc->move);
    }
    return (local_dist);
}

static void handle_npc_animation(npc_t *npc, int dist, int dir)
{
    sfTime time;

    time = sfClock_getElapsedTime(npc->anim);
    if (time.microseconds >= 55000) {
        npc->tx_rect.left += 64;
        if (npc->tx_rect.left >= 256)
            npc->tx_rect.left = 0;
        sfSprite_setTextureRect(npc->sp, npc->tx_rect);
        sfClock_restart(npc->anim);
    }
}

int action_management(npc_t *npc, player_t *player, int dist, int dir)
{
    static int travelled = 0;
    int travelled_cart = 0;

    if (check_npc_collision(npc, player) == 0) {
        handle_npc_animation(npc, dist, dir);
        travelled = handle_npc_move(npc, dir, travelled);
        update_npc_pos(npc, dir);
        travelled_cart = travelled / 32;
    }
    if (travelled_cart == dist)
        travelled = 0;
    return (travelled_cart);
}

int action_move_npc(npc_t *npc, player_t *player, int dist, int dir)
{
    static char flag = 1;
    int travelled_cart = 0;

    if (flag == 1) {
        npc->move = sfClock_create();
        npc->anim = sfClock_create();
        flag = 0;
    }
    travelled_cart = action_management(npc, player, dist, dir);
    if (travelled_cart == dist) {
        flag = 1;
        sfClock_destroy(npc->move);
        sfClock_destroy(npc->anim);
        return (END_NPC_ACT);
    }
    return (0);
}