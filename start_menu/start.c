/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void start_event(csfml_t *page, start_menu_t *start)
{
    if (page->event.type == sfEvtClosed || button_obj_is_hover \
    (&start->menu_buttons[1], page->window) && \
    page->event.key.code == sfMouseLeft)
        start->menu_buttons[1].action(page);
    if (page->event.type == sfEvtMouseButtonPressed \
    && page->event.key.code == sfMouseLeft) {
        if (button_obj_is_hover(&start->menu_buttons[0], page->window) && \
        page->event.key.code == sfMouseLeft)
            start->menu_buttons[0].action(page);
    }
}

static void start_display(start_menu_t *start, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, start->back.sp_back, NULL);
    sfRenderWindow_drawSprite(window, start->menu_buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, start->menu_buttons[1].sprite, NULL);
    sfRenderWindow_drawText(window, start->back.title, NULL);
    sfRenderWindow_drawText(window, start->menu_buttons[0].text, NULL);
    sfRenderWindow_drawText(window, start->menu_buttons[1].text, NULL);
    sfRenderWindow_display(window);
}

static void start_destroy(start_menu_t *start)
{
    sfText_destroy(start->menu_buttons[0].text);
    sfText_destroy(start->menu_buttons[1].text);
    sfText_destroy(start->back.title);
    sfSprite_destroy(start->back.sp_back);
    sfSprite_destroy(start->menu_buttons[0].sprite);
    sfSprite_destroy(start->menu_buttons[1].sprite);
    sfTexture_destroy(start->back.tx_back);
}

void start_menu(csfml_t *page)
{
    start_menu_t start;

    start_initialize(&start, page);
    while (page->act_scene == ID_START_MENU) {
        start_display(&start, page->window);
        check_buttons_hover(&start, page);
        while (sfRenderWindow_pollEvent(page->window, &page->event)) {
            start_event(page, &start);
        }
    }
    start_destroy(&start);
}