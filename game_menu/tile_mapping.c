/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tile_mapping
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

static int file_size(char *filepath)
{
    FILE *fp;
    char *buffer = NULL;
    size_t len = 0;
    int read = 0;
    int count = 0;

    fp = fopen(filepath, "r");
    for (count = 0; read != -1; count++)
        read = getline(&buffer, &len, fp);
    if (count > 0)
        free(buffer);
    return (count);
}

static char **init_map(game_scene_t *scene, char *filepath)
{
    FILE *fp;
    int size = file_size(filepath);
    char **map = malloc(sizeof(char *) * size);
    size_t len = 0;
    int read = 0;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        return (NULL);
    for (int i = 0; read != -1; i++) {
        map[i] = NULL;
        read = getline(&map[i], &len, fp);
        if (read != -1 && map[i][read - 1] == '\n')
            map[i][read - 1] = '\0';
        if (read == -1)
            map[i] = NULL;
    }
    return (map);
}

void init_game_scene(game_scene_t *scene)
{
    scene->starting_pos = (sfVector2f) {16 + 32 * 11, 16 + 32 * 11};
    scene->map_layer01 = init_map(scene, MAP_L01_FILE);
    scene->view_dist = malloc(sizeof(int *) * 2);
    scene->view_dist[0] = malloc(sizeof(int) * 2);
    scene->view_dist[1] = malloc(sizeof(int) * 2);
}