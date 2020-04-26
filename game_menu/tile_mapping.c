/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tile_mapping
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

static char *init_map(game_scene_t *scene, char *filepath)
{
    FILE *fp;
    char *buffer = NULL;
    char *line = NULL;
    size_t len = 0;
    int read = 0;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        return (NULL);
    read = getline(&buffer, &len, fp);
    while (read != -1) {
        read = getline(&line, &len, fp);
        if (read != -1)
            buffer = my_strcat(buffer, line);
    }
    free(line);
    return (buffer);
}

void init_game_scene(game_scene_t *scene)
{
    scene->starting_pos = (sfVector2f) {0, 0};
    scene->map_layer01 = init_map(scene, MAP_L01_FILE);
    scene->map_layer02 = init_map(scene, MAP_L02_FILE);
}

void map_display(char *map, game_scene_t *scene, sfSprite *tile, csfml_t *general)
{
    sfVector2f tile_pos;
    int rows[7] = {0, 32, 32 * 5, 0, 32, 0, 32};
    int cols[7] = {0, 0, 32 * 5, 32, 32, 64, 64};
    char tmp = 0;

    tile_pos = (sfVector2f) {0, 0};
    for (int i = 0; map != NULL && map[i] != '\0'; i++) {
        tmp = map[i];
        if (tmp == '\n')
            tile_pos = (sfVector2f) {-MAP_BLOC_SIZE_X, tile_pos.y + MAP_BLOC_SIZE_Y};
        else if (tmp != ' ') {
            sfSprite_setPosition(tile, tile_pos);
            sfSprite_setTextureRect(tile, (sfIntRect) \
                {rows[tmp - 48], cols[tmp - 48], MAP_BLOC_SIZE_X, MAP_BLOC_SIZE_Y});
            sfRenderWindow_drawSprite(general->window, tile, NULL);
            if (tmp == '1')
                player_check_collision(&general->player, tile_pos);
        }
        tile_pos.x += MAP_BLOC_SIZE_X;
    }
}