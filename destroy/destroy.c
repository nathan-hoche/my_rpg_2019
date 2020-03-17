/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** destroy
*/
#include "../include/my.h"

void main_destroy(csfml *page)
{
    sfSprite_destroy(page->back.s_back);
    sfTexture_destroy(page->back.t_back);
    sfRenderWindow_destroy(page->window);
}