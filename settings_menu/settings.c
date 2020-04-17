/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** settings menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int pause_event(csfml_t *page)
{
    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    }
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        return (0);
    return (1);
}

static void pause_display(pause_menu_t *pause, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, pause->back.sp_back, NULL);
    sfRenderWindow_display(window);
}

static void pause_initialize(pause_menu_t *pause)
{
    pause->back.tx_back = make_texture("src/space.png");
    pause->back.sp_back = make_sprite(pause->back.tx_back);
}

static void pause_destroy(pause_menu_t *pause)
{
    sfSprite_destroy(pause->back.sp_back);
    sfTexture_destroy(pause->back.tx_back);
}

void settings(csfml_t *page)
{
    pause_menu_t settings;
    int active = 1;

    pause_initialize(&settings);
    while (active != 0) {
        pause_display(&settings, page->window);
        if (sfRenderWindow_pollEvent(page->window, &page->event))
            active = pause_event(page);
    }
    pause_destroy(&settings);
}