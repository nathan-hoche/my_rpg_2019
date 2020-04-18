/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** choose_skin
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int skin_event(csfml_t *page)
{
    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    } else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        return (0);
    else
        event_skin(page);
    return (1);
}

static void skin_display(skin_menu_t *skin, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, skin->back.sp_back, NULL);
    sfRenderWindow_display(window);
}

static void skin_initialize(skin_menu_t *skin)
{
    skin->back.tx_back = make_texture("src/space.png");
    skin->back.sp_back = make_sprite(skin->back.tx_back);
}

static void skin_destroy(skin_menu_t *skin)
{
    sfSprite_destroy(skin->back.sp_back);
    sfTexture_destroy(skin->back.tx_back);
}

void skin(csfml_t *page)
{
    skin_menu_t skin;
    int active = 1;

    skin_initialize(&skin);
    while (active != 0) {
        skin_display(&skin, page->window);
        if (sfRenderWindow_pollEvent(page->window, &page->event))
            active = skin_event(page);
    }
    skin_destroy(&skin);
}