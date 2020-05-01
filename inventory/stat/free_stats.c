/*
** EPITECH PROJECT, 2020
** free_stats.c
** File description:
** free_stats
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

void free_stats(stats_t *stats)
{
    sfText_destroy(stats->speed_val);
    sfText_destroy(stats->def_val);
    sfText_destroy(stats->att_val);
    sfText_destroy(stats->speed_txt);
    sfText_destroy(stats->def_txt);
    sfText_destroy(stats->att_txt);
    sfRectangleShape_destroy(stats->status);
    free(stats->stat);
}