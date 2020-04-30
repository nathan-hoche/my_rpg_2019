/*
** EPITECH PROJECT, 2020
** stat_player.c
** File description:
** stat_player
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

char *initialize_stats(inventory_t *inventory, char *buf, char *line, int i)
{
    char **temp = NULL;

    inventory->stats.stat[i] = malloc(sizeof(int) * STAT_DATA);
    buf = my_strcat(buf, line);
    temp = my_str_to_word_array(line, ':');
    inventory->stats.stat[i][0] = my_getnbr(temp[1]);
    inventory->stats.stat[i][1] = my_getnbr(temp[2]);
    inventory->stats.stat[i][2] = my_getnbr(temp[3]);
    free(temp);
    return (buf);
}