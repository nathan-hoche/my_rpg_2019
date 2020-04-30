/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** htp menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int htp_event(csfml_t *page)
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

static void htp_display(htp_menu_t *htp, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, htp->back.sp_back, NULL);
    sfRenderWindow_display(window);
}

static void htp_initialize(htp_menu_t *htp)
{
    htp->back.tx_back = make_texture(BACKGROUND_1);
    htp->back.sp_back = make_sprite(htp->back.tx_back);
}

static void htp_destroy(htp_menu_t *htp)
{
    sfSprite_destroy(htp->back.sp_back);
    sfTexture_destroy(htp->back.tx_back);
}

void how_to_play(csfml_t *page)
{
    htp_menu_t htp;
    int active = 1;

    htp_initialize(&htp);
    while (active != 0) {
        htp_display(&htp, page->window);
        if (sfRenderWindow_pollEvent(page->window, &page->event) && \
        active != 0)
            active = htp_event(page);
    }
    htp_destroy(&htp);
}