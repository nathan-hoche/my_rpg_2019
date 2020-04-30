/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_start
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void action_button_hover(button_t *button, csfml_t *core)
{
    sfColor flyover_color = {250, 255, 100, 255};
    sfColor base_color = {250, 255, 255, 255};

    if (button->state == 0 && button_obj_is_hover(button, core->window)) {
        sfSprite_setColor(button->sprite, flyover_color);
        button->state = 1;
    } else if (button->state == 1 && \
    button_obj_is_hover(button, core->window) == 0) {
        sfSprite_setColor(button->sprite, base_color);
        button->state = 0;
    }
}

void check_buttons_hover(start_menu_t *start, csfml_t *page)
{
    for (int i = 0; i < NB_START_MENU_B; i++)
        start->menu_buttons[i].hover(&start->menu_buttons[i], page);
}