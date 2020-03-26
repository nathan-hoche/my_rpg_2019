/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** initialize_window
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

void initialize_window(csfml *page)
{
    page->mode.width = 1920;
    page->mode.height = 1080;
    page->mode.bitsPerPixel = 32;

    page->window = sfRenderWindow_create(page->mode,
                            NULL, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(page->window, 30);
}