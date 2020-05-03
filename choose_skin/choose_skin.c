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
    page->event.type == sfEvtKeyPressed) {
        sfSound_play(page->music.sound_but);
        return (0);
    }
    if (page->event.key.code == sfMouseLeft && \
        page->event.type == sfEvtMouseButtonPressed)
        return (event_skin(page));
    return (1);
}

static void skin_display(skin_menu_t *skin, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, skin->back.sp_back, NULL);
    sfRenderWindow_drawSprite(window, skin->male, NULL);
    sfRenderWindow_drawSprite(window, skin->female, NULL);
    sfRenderWindow_drawText(window, skin->title, NULL);
    sfRenderWindow_display(window);
}

static void skin_initialize(skin_menu_t *skin, player_t *player, \
sfFont *font, music_t *music)
{
    skin->back.tx_back = make_texture(BACKGROUND_1);
    skin->back.sp_back = make_sprite(skin->back.tx_back);
    skin->title = make_text(font, "Choose your skin!", \
    (sfVector2f) {640, 40} , 80);
    skin->female = make_sprite(player->texture_female);
    skin->male = make_sprite(player->texture_male);
    sfSprite_setTextureRect(skin->female, player->player_rect);
    sfSprite_setTextureRect(skin->male, player->player_rect);
    sfSprite_setPosition(skin->female, (sfVector2f) {600, 300});
    sfSprite_setPosition(skin->male, (sfVector2f) {1050, 300});
    sfSprite_setScale(skin->male, (sfVector2f) {4, 4});
    sfSprite_setScale(skin->female, (sfVector2f) {4, 4});
}

static void skin_destroy(skin_menu_t *skin, csfml_t *page)
{
    sfSprite_destroy(skin->back.sp_back);
    sfSprite_destroy(skin->male);
    sfSprite_destroy(skin->female);
    sfTexture_destroy(skin->back.tx_back);
}

void skin(csfml_t *page)
{
    skin_menu_t skin;
    int active = 1;

    skin_initialize(&skin, &page->player, page->font_itim, &page->music);
    while (active != 0) {
        skin_display(&skin, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event) \
        && active != 0)
            active = skin_event(page);
    }
    skin_destroy(&skin, page);
}