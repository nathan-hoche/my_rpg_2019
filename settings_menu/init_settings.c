/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** settings menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void sounds_text_initialize(settings_menu_t *set, csfml_t *page)
{
    char *str_lvl_music = my_getstr(page->settings.music_lvl);
    char *str_lvl_fx = my_getstr(page->settings.fx_lvl);

    set->txt_music.pos = (sfVector2f) {1920/2 - 500, 1080/2 - 150};
    set->txt_fx.pos = (sfVector2f) {1920/2 - 350, 1080/2 + 50};
    set->txt_music.text = \
        make_text(page->font_itim, "MUSIC", set->txt_music.pos, 80);
    set->txt_fx.text = make_text(page->font_itim, "FX", set->txt_fx.pos, 80);
    set->txt_lvl_music.pos = (sfVector2f) {1920/2 - 50, 1080/2 - 150};
    set->txt_lvl_fx.pos = (sfVector2f) {1920/2 - 50, 1080/2 + 50};
    set->txt_lvl_music.text = \
        make_text(page->font_itim, str_lvl_music, set->txt_lvl_music.pos, 80);
    set->txt_lvl_fx.text = \
        make_text(page->font_itim, str_lvl_fx, set->txt_lvl_fx.pos, 80);
    free(str_lvl_music);
    free(str_lvl_fx);
}

static void buttons_exit_sprite_initialize(settings_menu_t *set, \
csfml_t *page)
{
    set->buttons[4].sprite = make_sprite(page->button_2);
    set->buttons[4].sp_rect = (sfIntRect) {0, 0, 100, 100};
    sfSprite_setTextureRect(set->buttons[4].sprite, set->buttons[4].sp_rect);
    set->buttons[4].sp_pos = (sfVector2f) {12, 12};
    sfSprite_setPosition(set->buttons[4].sprite, set->buttons[4].sp_pos);
}

static void buttons_sounds_sprite_initialize(settings_menu_t *set, \
csfml_t *page)
{
    set->buttons[0].sprite = make_sprite(page->button_2);
    set->buttons[1].sprite = make_sprite(page->button_2);
    set->buttons[2].sprite = make_sprite(page->button_2);
    set->buttons[3].sprite = make_sprite(page->button_2);
    set->buttons[0].sp_rect = (sfIntRect) {100, 0, 100, 100};
    set->buttons[1].sp_rect = (sfIntRect) {0, 0, 100, 100};
    set->buttons[2].sp_rect = (sfIntRect) {100, 0, 100, 100};
    set->buttons[3].sp_rect = (sfIntRect) {0, 0, 100, 100};
    sfSprite_setTextureRect(set->buttons[0].sprite, set->buttons[0].sp_rect);
    sfSprite_setTextureRect(set->buttons[1].sprite, set->buttons[1].sp_rect);
    sfSprite_setTextureRect(set->buttons[2].sprite, set->buttons[2].sp_rect);
    sfSprite_setTextureRect(set->buttons[3].sprite, set->buttons[3].sp_rect);
    set->buttons[0].sp_pos = (sfVector2f) {1920/2 - 200, 1080/2 - 150};
    set->buttons[1].sp_pos = (sfVector2f) {1920/2 + 100, 1080/2 - 150};
    set->buttons[2].sp_pos = (sfVector2f) {1920/2 - 200, 1080/2 + 50};
    set->buttons[3].sp_pos = (sfVector2f) {1920/2 + 100, 1080/2 + 50};
    sfSprite_setPosition(set->buttons[0].sprite, set->buttons[0].sp_pos);
    sfSprite_setPosition(set->buttons[1].sprite, set->buttons[1].sp_pos);
    sfSprite_setPosition(set->buttons[2].sprite, set->buttons[2].sp_pos);
    sfSprite_setPosition(set->buttons[3].sprite, set->buttons[3].sp_pos);
}

static void settings_buttons_initialize(settings_menu_t *set, csfml_t *page)
{
    set->back.tx_back = make_texture(BACKGROUND_1);
    set->back.sp_back = make_sprite(set->back.tx_back);
    set->buttons = malloc(sizeof(button_t) * NB_SET_MENU_B);
    set->buttons[0].state = -1;
    set->buttons[1].state = -1;
    set->buttons[2].state = -1;
    set->buttons[3].state = -1;
    set->buttons[4].state = -1;
    set->buttons[0].hover = NULL;
    set->buttons[1].hover = NULL;
    set->buttons[2].hover = NULL;
    set->buttons[3].hover = NULL;
    set->buttons[4].hover = NULL;
    set->buttons[0].action = &action_minus_music;
    set->buttons[1].action = &action_plus_music;
    set->buttons[2].action = &action_minus_fx;
    set->buttons[3].action = &action_plus_fx;
    set->buttons[4].action = &action_return;
    buttons_sounds_sprite_initialize(set, page);
    buttons_exit_sprite_initialize(set, page);
}

void settings_initialize(settings_menu_t *set, csfml_t *page)
{
    settings_buttons_initialize(set, page);
    sounds_text_initialize(set, page);
}