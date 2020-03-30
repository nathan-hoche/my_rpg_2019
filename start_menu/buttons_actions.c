/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttons actions
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void action_start_button(csfml_t *page)
{
    page->act_scene = ID_GAME;
}

void action_quit_button(csfml_t *page)
{
    page->act_scene = ID_CLOSE;
}