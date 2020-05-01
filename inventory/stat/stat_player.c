/*
** EPITECH PROJECT, 2020
** stat_player.c
** File description:
** stat_player
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

void display_texts(stats_t *stats)
{
    return;
}

static void initialize_texts(stats_t *stats, csfml_t *general, int i)
{
    sfVector2f att_txt_pos = (sfVector2f) {300, 200};
    sfVector2f def_txt_pos = (sfVector2f) {300, 300};
    sfVector2f spe_txt_pos = (sfVector2f) {300, 400};
    stats->att_txt = make_text(general->font_itim, "ATTACK:", att_txt_pos, 10);
    stats->def_txt = make_text(general->font_itim, "DEFENSE:", def_txt_pos, 3);
    stats->speed_txt = make_text(general->font_itim, "SPEED:", spe_txt_pos, 10);
    sfText_setString(stats->att_txt, my_getstr(stats->stat[i][0]));
    sfText_setString(stats->def_txt, my_getstr(stats->stat[i][1]));
    sfText_setString(stats->speed_txt, my_getstr(stats->stat[i][2]));

}

void initialize_graphical_stats(inventory_t *inventory, csfml_t *general, int i)
{
    sfVector2f get_pl_pos;

    get_pl_pos = sfSprite_getPosition(general->player.player);
    get_pl_pos.x -= 595;
    get_pl_pos.y += 190;
    inventory->stats.status = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory->stats.status, sfBlack);
    sfRectangleShape_setOutlineColor(inventory->stats.status, sfWhite);
    sfRectangleShape_setOutlineThickness(inventory->stats.status, 1.5);
    sfRectangleShape_setSize(inventory->stats.status, (sfVector2f) {250, 120});
    sfRectangleShape_setPosition(inventory->stats.status, get_pl_pos);
    initialize_texts(&inventory->stats, general, i);
}

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