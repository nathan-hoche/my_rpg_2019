/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** turn core of the fight system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void fight_button_hover(fight_button_t *button)
{
    if (button->state == 0 || button->state == 3) {
        sfText_setColor(button->txt, (sfColor) {250, 255, 42, 255});
        button->state = 1;
    }
}

void fight_button_no_hover(fight_button_t *button)
{
    if (button->state == 1 || button->state == 3) {
        sfText_setColor(button->txt, (sfColor) {250, 255, 255, 255});
        button->state = 0;
    }
}

void fight_button_clicked(fight_button_t *button)
{
    sfText_setColor(button->txt, (sfColor) {200, 0, 0, 255});
    button->state = 3;
}