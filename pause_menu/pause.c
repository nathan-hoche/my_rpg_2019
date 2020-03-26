/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
**  play menu pause
*/

#include "../include/my_rpg.h"
#include "../include/my.h"

static int pause_event(csfml *page, int x)
{
    if (page->event.type == sfEvtClosed)
        return (-1);
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        return (0);
    return (1);
}

static void pause_display(pause_menu_t *pause, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, pause->back.s_back, NULL);
    sfRenderWindow_display(window);
}

static void pause_initialize(pause_menu_t *pause)
{
    pause->back.t_back = make_texture("src/space.png");
    pause->back.s_back = make_sprite(pause->back.t_back);
}

static void pause_destroy(pause_menu_t *pause)
{
    sfSprite_destroy(pause->back.s_back);
    sfTexture_destroy(pause->back.t_back);
}

int pause_menu(csfml *page)
{
    pause_menu_t pause;
    int x = 1;

    pause_initialize(&pause);
    while (x == 1) {
        pause_display(&pause, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event) && x != 0)
            x = pause_event(page, x);
    }
    pause_destroy(&pause);
    return (x);
}