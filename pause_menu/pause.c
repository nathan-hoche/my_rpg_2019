/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play menu pause
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int pause_event(csfml_t *page, pause_menu_t *pause)
{
    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    } else if (page->event.type == sfEvtKeyPressed && \
    page->event.key.code == sfKeyEscape)
        return (0);
    return (pause_check_button(page, pause));
}

static void pause_display(pause_menu_t *pause, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, pause->back.sp_back, NULL);
    for (int i = 0, x = 100; i != 4; i++, x += 200) {
        sfSprite_setPosition(pause->button, (sfVector2f) {300, x});
        sfRenderWindow_drawSprite(window, pause->button, NULL);
    }
    sfRenderWindow_drawText(window, pause->resume, NULL);
    sfRenderWindow_drawText(window, pause->htp, NULL);
    sfRenderWindow_drawText(window, pause->settings, NULL);
    sfRenderWindow_drawText(window, pause->exit, NULL);
    sfRenderWindow_display(window);
}

static void pause_initialize(pause_menu_t *pause, csfml_t *page)
{
    pause->back.tx_back = make_texture(BACKGROUND_2);
    pause->back.sp_back = make_sprite(pause->back.tx_back);
    pause->button = make_sprite(page->button_1);
    pause->resume = make_text(page->font_itim, "RESUME GAME", \
    (sfVector2f) {340, 125}, 30);
    pause->htp = make_text(page->font_itim, "HOW TO PLAY", \
    (sfVector2f) {340, 325}, 30);
    pause->settings = make_text(page->font_itim, "SETTINGS", \
    (sfVector2f) {345, 520}, 40);
    pause->exit = make_text(page->font_itim, "EXIT", \
    (sfVector2f) {380, 715}, 50);
    sfSprite_setPosition(pause->button, (sfVector2f) {400, 200});
}

static void pause_destroy(pause_menu_t *pause)
{
    sfSprite_destroy(pause->back.sp_back);
    sfSprite_destroy(pause->button);
    sfText_destroy(pause->exit);
    sfText_destroy(pause->htp);
    sfText_destroy(pause->resume);
    sfText_destroy(pause->settings);
    sfTexture_destroy(pause->back.tx_back);
}

void pause_menu(csfml_t *page)
{
    pause_menu_t pause;
    int active = 1;

    sfRenderWindow_setView(page->window, page->views.default_view);
    pause_initialize(&pause, page);
    while (active != 0) {
        pause_display(&pause, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event) && \
        active != 0)
            active = pause_event(page, &pause);
    }
    pause_destroy(&pause);
    sfRenderWindow_setView(page->window, page->views.actual_view);
}