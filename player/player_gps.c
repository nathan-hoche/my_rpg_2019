/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player gps system
*/

#include "my_rpg.h"
#include "struct.h"

static void set_view_direction(player_t *player)
{
    int looking[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    player->pos_view = (sfVector2i) {player->pos_cart.x + \
    looking[player->dir_view - 1][0], \
    player->pos_cart.y + looking[player->dir_view - 1][1]};
}

void player_gps(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->player);

    player->pos_cart.x = pos.x / 32;
    player->pos_cart.y = pos.y / 32;
    player->pos_px.x = pos.x;
    player->pos_px.y = pos.y;
    set_view_direction(player);
}