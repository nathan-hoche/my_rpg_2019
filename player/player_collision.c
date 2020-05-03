/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collision
*/

#include "my_rpg.h"
#include "struct.h"

static int is_collide_npc(int x, int y, game_menu_t *game, player_t *player)
{
    for (int i = 0; i < 2; i++) {
        if (x == game->npc[i].pos_cart.x && y == game->npc[i].pos_cart.y)
            return (1);
        if (x == game->npc[i].traj_cart.x && y == game->npc[i].traj_cart.y)
            return (1);
    }
    if (x == 46) {
        game->on_msg = -2;
        return (1);
    }
    return (0);
}

static int is_collide(char value)
{
    char *collide_list = " 1234:=>?@BCDFGH\0";

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
        game, player) == 1))
        return (1);
    if (key == sfKeyQ && \
        (is_collide(map[player->pos_cart.y][player->pos_cart.x - 1]) == 1 || \
        is_collide_npc(player->pos_cart.x - 1, player->pos_cart.y, \
        game, player) == 1))
        return (1);
    return (0);
}

int is_collide_vertical(int key, player_t *player, game_menu_t *game, \
char **map)
{
    if (key == sfKeyS && \
    (is_collide(map[player->pos_cart.y + 1][player->pos_cart.x]) == 1 || \
    is_collide_npc(player->pos_cart.x, player->pos_cart.y + 1, \
    game, player) == 1))
        return (1);
    if (key == sfKeyZ && \
    (is_collide(map[player->pos_cart.y - 1][player->pos_cart.x]) == 1 || \
    is_collide_npc(player->pos_cart.x, player->pos_cart.y - 1, \
    game, player) == 1))
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