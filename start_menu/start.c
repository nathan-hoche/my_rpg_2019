/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start
*/

#include "../include/my_rpg.h"
#include "../include/my.h"

static int start_event(csfml *page, start_menu_t *start)
{
    if (page->event.type == sfEvtClosed || (button_is_clicked( \
    start->but.pos_but_exit, page->size_button, page->window) == 0) \
    && page->event.key.code == sfMouseLeft)
        return (-1);
    if (page->event.key.code == sfMouseLeft)
        if (button_is_clicked(start->but.pos_but_play, \
        page->size_button, page->window) == 0)
            return (1);
    return (0);
}

static void start_display(start_menu_t *start, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, start->back.s_back, NULL);
    sfRenderWindow_drawSprite(window, start->but.play_button, NULL);
    sfRenderWindow_drawSprite(window, start->but.exit_button, NULL);
    sfRenderWindow_drawText(window, start->back.title, NULL);
    sfRenderWindow_drawText(window, start->but.start_txt, NULL);
    sfRenderWindow_drawText(window, start->but.exit_txt, NULL);
    sfRenderWindow_display(window);
}

static void start_destroy(start_menu_t *start)
{
    sfText_destroy(start->but.start_txt);
    sfText_destroy(start->back.title);
    sfSprite_destroy(start->back.s_back);
    sfSprite_destroy(start->but.play_button);
    sfTexture_destroy(start->back.t_back);
}

int start_menu(csfml *page)
{
    start_menu_t start;
    int x = 0;

    start_initialize(&start, page);
    while (x == 0) {
        start_display(&start, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            x = start_event(page, &start);
    }
    start_destroy(&start);
    return (x);
}