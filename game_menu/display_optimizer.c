/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_optimizer
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static inline int *compute_min(player_t *playr, int *view_dist)
{
    int min_y = 0;
    int min_x = 0;

    if (playr->pos_px.x >= 15)
        min_x = playr->pos_cart.x - 15;
    if (playr->pos_px.y >= 9)
        min_y = playr->pos_cart.y - 9;
    view_dist[0] = min_x;
    view_dist[1] = min_y;
    return (view_dist);
}

static inline int *compute_max(player_t *playr, int *view_dist, char **map)
{
    int max_y = 0;
    int max_x = 0;

    for (int x = playr->pos_cart.x; map[playr->pos_cart.y][x]; x++, max_x++);
    for (int y = playr->pos_cart.y; map[y]; y++, max_y++);
    if (max_x >= 15)
        max_x = playr->pos_cart.x + 15;
    else
        max_x = playr->pos_cart.x + max_x;
    if (max_y >= 9)
        max_y = playr->pos_cart.y + 9;
    else
        max_x = playr->pos_cart.y + max_y;
    view_dist[0] = max_x;
    view_dist[1] = max_y;
    return (view_dist);
}

int **display_optimization(char **map, player_t *playr, int **view_dist)
{
    view_dist[0] = compute_min(playr, view_dist[0]);
    view_dist[1] = compute_max(playr, view_dist[1], map);
    return (view_dist);
}