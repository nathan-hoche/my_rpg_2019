/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** initialize
*/
#include "../include/my.h"

void main_initialize(csfml *page)
{
    initialize_window(page);
    page->back.t_back = make_texture("src/space.png");
    page->back.s_back = make_sprite(page->back.t_back);
}