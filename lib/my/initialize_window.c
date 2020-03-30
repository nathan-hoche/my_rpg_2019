/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** initialize_window
*/

#include "../../include/my_rpg.h"

void initialize_window(csfml_t *page)
{
    page->mode.width = BASE_WIDTH;
    page->mode.height = BASE_HEIGHT;
    page->mode.bitsPerPixel = 32;

    page->window = sfRenderWindow_create(page->mode,
                            NULL, sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(page->window, 30);
}