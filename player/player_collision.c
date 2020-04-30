/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collision
*/

#include "my_rpg.h"
#include "struct.h"

static int is_collide(char value)
{
    char collide_list[] = {'2', '3', '4', '5', '6', '7', '\0'};

    for (int i = 0; collide_list[i]; i++) {
        if (value == collide_list[i])
            return (1);
    }
    return (0);
}

int player_collision_core(int key, player_t *playr, game_menu_t *game)
{
    char **map = game->game_scene.map_layer01;

    if (key == sfKeyD && is_collide \
    (map[playr->pos_cart.y][playr->pos_cart.x + 1]) == 1)
        return (1);
    else if (key == sfKeyQ && is_collide \
    (map[playr->pos_cart.y][playr->pos_cart.x - 1]) == 1)
        return (1);
    if (key == sfKeyS && is_collide \
    (map[playr->pos_cart.y + 1][playr->pos_cart.x]) == 1)
        return (1);
    else if (key == sfKeyZ && is_collide \
    (map[playr->pos_cart.y - 1][playr->pos_cart.x]) == 1)
        return (1);
    return (0);
}

void check_collisions_with_npc(player_t *player, npc_t *npc)
{
    if ((player->pos_traj.x == npc->pos_cart.x && \
    player->pos_traj.y == npc->pos_cart.y - 1) || \
    (player->pos_traj.x == npc->pos_cart.x) && \
    (player->pos_traj.y == npc->pos_cart.y)) {
        player->on_move = 0;
        player->on_anim = 0;
    }
    if ((player->pos_traj.x == npc->pos_cart.x && \
    player->pos_traj.y - 1 == npc->pos_cart.y - 1) || \
    (player->pos_traj.x == npc->pos_cart.x) && \
    (player->pos_traj.y - 1 == npc->pos_cart.y)) {
        player->on_move = 0;
        player->on_anim = 0;
    }
}