/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int fight_event(csfml_t *page)
{
    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    }
    else if (page->event.type == sfEvtKeyPressed && \
    page->event.key.code == sfKeyEscape)
        return (0);
    return (1);
}

static void fight_display(pause_menu_t *pause, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, pause->back.sp_back, NULL);
    sfRenderWindow_display(window);
}

static void fight_initialize(pause_menu_t *pause)
{
    pause->back.tx_back = make_texture(BACKGROUND_1);
    pause->back.sp_back = make_sprite(pause->back.tx_back);
}

static void fight_destroy(pause_menu_t *pause)
{
    sfSprite_destroy(pause->back.sp_back);
    sfTexture_destroy(pause->back.tx_back);
}

void fight_core(csfml_t *page, game_menu_t *game)
{
    pause_menu_t pause;
    int active = 1;

    sfRenderWindow_setView(page->window, page->views.default_view);
    fight_initialize(&pause);
    while (active != 0) {
        fight_display(&pause, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event) && \
        active != 0 && page->act_scene != ID_CLOSE)
            active = fight_event(page);
    }
    fight_destroy(&pause);
    sfRenderWindow_setView(page->window, page->views.actual_view);
}