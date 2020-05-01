/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collision
*/

#include "my_rpg.h"
#include "struct.h"

static int is_collide_npc(int x, int y, npc_t *npc, player_t *player)
{
    if ((x == npc->pos_cart.x && y == npc->pos_cart.y - 1) || \
    (x == npc->pos_cart.x && y == npc->pos_cart.y))
        return (1);
    if ((x == npc->pos_cart.x && y - 1 == npc->pos_cart.y - 1) || \
    (x == npc->pos_cart.x && y - 1 == npc->pos_cart.y))
        return (1);
    return (0);
}

static int is_collide(char value)
{
    char *collide_list = "234567\0";

    for (int i = 0; collide_list[i]; i++) {
        if (value == collide_list[i])
            return (1);
    }
    return (0);
}

int is_collide_horizontal(int key, player_t *player, game_menu_t *game, \
char **map)
{
    if (key == sfKeyD && \
        (is_collide(map[player->pos_cart.y][player->pos_cart.x + 1]) == 1 || \
        is_collide_npc(player->pos_cart.x + 1, player->pos_cart.y, \
        &game->npc, player) == 1))
        return (1);
    if (key == sfKeyQ && \
        (is_collide(map[player->pos_cart.y][player->pos_cart.x - 1]) == 1 || \
        is_collide_npc(player->pos_cart.x - 1, player->pos_cart.y, \
        &game->npc, player) == 1))
        return (1); 
    return (0);
}

int is_collide_vertical(int key, player_t *player, game_menu_t *game, \
char **map)
{
    if (key == sfKeyS && \
    (is_collide(map[player->pos_cart.y + 1][player->pos_cart.x]) == 1 || \
    is_collide_npc(player->pos_cart.x, player->pos_cart.y + 1, \
    &game->npc, player) == 1))
        return (1);
    if (key == sfKeyZ && \
    (is_collide(map[player->pos_cart.y - 1][player->pos_cart.x]) == 1 || \
    is_collide_npc(player->pos_cart.x, player->pos_cart.y - 1, \
    &game->npc, player) == 1))
        return (1);
    return (0);
}

int player_collision_core(int key, player_t *player, game_menu_t *game)
{
    char **map = game->game_scene.map_layer01;

    if (is_collide_horizontal(key, player, game, map) == 1 || \
        is_collide_vertical(key, player, game, map) == 1)
        return (1);
    return (0);
}