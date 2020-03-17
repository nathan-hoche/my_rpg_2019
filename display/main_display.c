/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** main_display
*/
#include "../include/my.h"

void main_display(csfml *page)
{
    sfRenderWindow_clear(page->window, sfWhite);
    sfRenderWindow_drawSprite(page->window, page->back.s_back, NULL);
    sfRenderWindow_display(page->window);
}