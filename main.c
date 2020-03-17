/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** main
*/
#include "include/my.h"

void poll_evt(csfml *page)
{
    while (sfRenderWindow_pollEvent(page->window, &page->event)) {
        if (page->event.type == sfEvtClosed)
            sfRenderWindow_close(page->window);
    }
}

int game_loop(int ac)
{
    int x = 0;
    csfml page;

    main_initialize(&page);
    while (sfRenderWindow_isOpen(page.window) && x != 2) {
        poll_evt(&page);
        main_display(&page);
    }
    main_destroy(&page);
    return (0);
}

int main(int ac, char **av)
{
    int x = game_loop(ac);
    return (x);
}