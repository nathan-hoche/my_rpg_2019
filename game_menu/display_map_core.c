/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage dispay of maps
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void tile_writing(int *cursor, sfVector2f cursor_px, \
game_menu_t *game, csfml_t *general)
{
    int blocks[13][2] = {{0, 0}, {0, 32}, {32, 32}, {32, 64}, {0, 64}, \
    {0, 4 * 32}, {32, 32 * 4}, {7 * 32, 0}, {5 * 32, 0}, {6 * 32, 0}, \
    {0, 5 * 32}, {0, 6 * 32}, {4 * 32, 21 * 32}};

    if (cursor[0] != ' ' && \
    cursor[2] >= game->game_scene.view_dist[0][1] && cursor[1] >= \
    game->game_scene.view_dist[0][0] && cursor[2] <= \
    game->game_scene.view_dist[1][1] \
    && cursor[1] <= game->game_scene.view_dist[1][0]) {
        sfSprite_setPosition(game->tile, cursor_px);
        sfSprite_setTextureRect(game->tile, (sfIntRect) \
        {blocks[cursor[0] - 48][0], \
        blocks[cursor[0] - 48][1], BLOCK_SIZE_X, BLOCK_SIZE_Y});
        sfRenderWindow_drawSprite(general->window, game->tile, NULL);
    }
}

static void map_display(char **map, game_menu_t *game, csfml_t *general)
{
    sfVector2f cursor_px = {0, 0};
    int cursor[3] = {0, 0, 0};

    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            cursor[0] = map[y][x];
            cursor[1] = x;
            cursor[2] = y;
            tile_writing(cursor, cursor_px, game, general);
            cursor_px.x += 32;
        }
        cursor_px.y += 32;
        cursor_px.x = 0;
    }
}

void display_map_core(game_menu_t *game, csfml_t *general)
{
    game->game_scene.view_dist = display_optimization \
        (game->game_scene.map_layer01, &general->player, \
        game->game_scene.view_dist);
    map_display(game->game_scene.map_layer02, \
        game, general);
    map_display(game->game_scene.map_layer01, \
        game, general);
}