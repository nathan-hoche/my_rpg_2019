/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tile_mapping
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

static void init_map(game_scene_t *scene)
{
    FILE *fp;
    char *buffer = NULL;
    char *line = NULL;
    size_t len = 0;
    int read = 0;

    fp = fopen(scene->map_file, "r");
    if (fp == NULL)
        return;
    read = getline(&buffer, &len, fp);
    while (read != -1) {
        read = getline(&line, &len, fp);
        if (read != -1)
            buffer = my_strcat(buffer, line);
    }
    scene->map = buffer;
    free(line);
}

void init_game_scene(game_scene_t *scene)
{
    scene->starting_pos = (sfVector2f) {0, 0};
    init_map(scene);
}

void map_display(game_scene_t *scene, sfSprite *tile, sfRenderWindow *window)
{
    sfVector2f tile_pos;
    int rows[3] = {0, 32, 32*5};
    int cols[3] = {0, 0, 32*5};
    char tmp = 0;

    tile_pos = (sfVector2f) {0, 0};
    for (int i = 0; scene->map != NULL && scene->map[i] != '\0'; i++) {
        tmp = scene->map[i];
        if (scene->map[i] == '\n')
            tile_pos = (sfVector2f) {-32, tile_pos.y + 32};
        else if (scene->map[i] != ' ') {
            sfSprite_setPosition(tile, tile_pos);
            sfSprite_setTextureRect(tile, (sfIntRect) {rows[tmp-48], \
            cols[tmp-48], 32, 32});
            sfRenderWindow_drawSprite(window, tile, NULL);
        }
        tile_pos.x += 32;
    }
}