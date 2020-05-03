/*
** EPITECH PROJECT, 2020
** stat_player.c
** File description:
** stat_player
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"
#include <unistd.h>

void display_status(csfml_t *general, stats_panel_t *stats)
{
    sfRenderWindow_drawText(general->window, stats->att_txt, NULL);
    sfRenderWindow_drawText(general->window, stats->def_txt, NULL);
    sfRenderWindow_drawText(general->window, stats->speed_txt, NULL);
    sfRenderWindow_drawText(general->window, stats->att_val, NULL);
    sfRenderWindow_drawText(general->window, stats->def_val, NULL);
    sfRenderWindow_drawText(general->window, stats->speed_val, NULL);
}

void initialize_texts(stats_panel_t *stats, csfml_t *general)
{
    stats->att_val = make_text(general->font_itim, \
    my_getstr(stats->stat[0]), (sfVector2f) {10, 10}, 20);
    stats->def_val = make_text(general->font_itim, \
    my_getstr(stats->stat[1]), (sfVector2f) {10, 50}, 20);
    stats->speed_val = make_text(general->font_itim, \
    my_getstr(stats->stat[2]), (sfVector2f) {10, 90}, 20);
    stats->att_txt = make_text(general->font_itim, "ATTACK:", \
    (sfVector2f) {10, 10}, 20);
    stats->def_txt = make_text(general->font_itim, "DEFENSE:", \
    (sfVector2f) {10, 50}, 20);
    stats->speed_txt = make_text(general->font_itim, \
    "SPEED:", (sfVector2f) {10, 90}, 20);
}

void set_stats_pos(inventory_t *inventory, csfml_t *general)
{
    sfVector2f pos;

    pos.x = general->player.pos_px.x;
    pos.y = general->player.pos_px.y;
    pos.x -= 465;
    pos.y += 100;
    sfRectangleShape_setPosition(inventory->stats.status, pos);
    sfText_setPosition(inventory->stats.att_val, \
    (sfVector2f) {pos.x + 95, pos.y + 10});
    sfText_setPosition(inventory->stats.def_val, \
    (sfVector2f) {pos.x + 100, pos.y + 50});
    sfText_setPosition(inventory->stats.speed_val, \
    (sfVector2f) {pos.x + 80, pos.y + 90});
    sfText_setPosition(inventory->stats.att_txt, \
    (sfVector2f) {pos.x + 10, pos.y + 10});
    sfText_setPosition(inventory->stats.def_txt, \
    (sfVector2f) {pos.x + 10, pos.y + 50});
    sfText_setPosition(inventory->stats.speed_txt, \
    (sfVector2f) {pos.x + 10, pos.y + 90});
}

void initialize_graphical_stats(inventory_t *inventory, csfml_t *general)
{
    inventory->stats.status = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory->stats.status, sfBlack);
    sfRectangleShape_setOutlineColor(inventory->stats.status, sfWhite);
    sfRectangleShape_setOutlineThickness(inventory->stats.status, 1.5);
    sfRectangleShape_setSize(inventory->stats.status, (sfVector2f) \
    {150, 175});
}

char *initialize_stats(inventory_t *inventory, char *buf, char *line, \
csfml_t *general)
{
    char **temp = NULL;

    buf = my_strcat(buf, line);
    temp = my_str_to_word_array(line, ':');
    inventory->stats.stat[0] += my_getnbr(temp[1]);
    inventory->stats.stat[1] += my_getnbr(temp[2]);
    inventory->stats.stat[2] += my_getnbr(temp[3]);
    free(temp);
    return (buf);
}