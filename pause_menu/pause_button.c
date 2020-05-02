/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_button
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int check_button(csfml_t *page, sfVector2f pos_but, int i)
{
    static void (*return_value[2])() = {how_to_play, settings};
    int if_close = 0;

    if (button_is_hover(pos_but, page->size_button, page->window) == 1) {
        sfSound_play(page->music.sound_but);
        if (i == 0)
            return (0);
        else if (i == 3)
            page->act_scene = ID_CLOSE;
        else
            return_value[i-1](page);
        if (page->act_scene == ID_CLOSE)
            return (0);
    }
    return (1);
}

int pause_check_button(csfml_t *page, pause_menu_t *pause)
{
    int pos_button[4][2] = {{300, 100}, {300, 300}, {300, 500}, {300, 700}};
    int value_check_button = 1;

    if (page->event.key.code == sfMouseLeft && \
        page->event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i != 4 && value_check_button != 0; i++)
            value_check_button = check_button(page, \
            (sfVector2f) {pos_button[i][0], pos_button[i][1]}, i);
    }
    return (value_check_button);
}