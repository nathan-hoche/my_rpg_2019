/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage dispay of maps
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

static int **display_optimization(char **map, player_t *playr, int **view_dist)
{
    view_dist[0] = compute_min(playr, view_dist[0]);
    view_dist[1] = compute_max(playr, view_dist[1], map);
    return (view_dist);
}

static void map_display(char **map, game_scene_t *scene, sfSprite *tile, \
csfml_t *general)
{
    sfVector2f cursor = {0, 0};
    int blocks[][2] = {{0, 0}, {0, 32}, {32, 32}, {32, 64}, {0, 64}, \
    {0, 4 * 32}, {32, 32 * 4}, {7 * 32, 0}, {5 * 32, 0}, {5 * 32, 32}};

    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            if (map[y][x] != ' ' && \
            y >= scene->view_dist[0][1] && x >= scene->view_dist[0][0] && \
            y <= scene->view_dist[1][1] && x <= scene->view_dist[1][0]) {
                sfSprite_setPosition(tile, cursor);
                sfSprite_setTextureRect(tile, (sfIntRect) \
                    {blocks[map[y][x] - 48][0], \
                    blocks[map[y][x] - 48][1], BLOCK_SIZE_X, BLOCK_SIZE_Y});
                sfRenderWindow_drawSprite(general->window, tile, NULL);
            }
            cursor.x += 32;
        }
        cursor = (sfVector2f) {0, cursor.y + 32};
    }
}

void display_map_core(game_menu_t *game, csfml_t *general)
{
    game->game_scene.view_dist = display_optimization \
        (game->game_scene.map_layer01, &general->player, \
        game->game_scene.view_dist);
    map_display(game->game_scene.map_layer01, \
        &game->game_scene, game->tile, general);
}