/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** htp menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int htp_event(csfml_t *page, htp_menu_t *htp)
{
    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    } else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        return (0);
    if (page->event.key.code == sfMouseLeft && \
        page->event.type == sfEvtMouseButtonPressed)
        if (button_is_clicked(htp->pos_but, page->size_button, \
        page->window) == 0) {
            page->act_scene = ID_START_MENU;
            return (0);
        }
    return (1);
}

static void htp_display(htp_menu_t *htp, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, htp->back.sp_back, NULL);
    sfRenderWindow_drawSprite(window, htp->exit_button, NULL);
    sfRenderWindow_drawText(window, htp->exit, NULL);
    sfRenderWindow_display(window);
}

static void htp_initialize(csfml_t *page, htp_menu_t *htp)
{
    htp->back.tx_back = make_texture(BACKGROUND_2);
    htp->back.sp_back = make_sprite(htp->back.tx_back);
    htp->exit_button = make_sprite(page->button_1);
    htp->pos_but = (sfVector2f) {1600, 900};
    sfSprite_setPosition(htp->exit_button, htp->pos_but);
    htp->exit = make_text(page->font_itim, "EXIT", \
    (sfVector2f) {1675, 915}, 50);
}

static void htp_destroy(htp_menu_t *htp)
{
    sfSprite_destroy(htp->back.sp_back);
    sfSprite_destroy(htp->exit_button);
    sfText_destroy(htp->exit);
    sfTexture_destroy(htp->back.tx_back);
}

void how_to_play(csfml_t *page)
{
    htp_menu_t htp;
    int active = 1;

    htp_initialize(page, &htp);
    while (active != 0) {
        htp_display(&htp, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event) && \
        active != 0)
            active = htp_event(page, &htp);
    }
    htp_destroy(&htp);
}