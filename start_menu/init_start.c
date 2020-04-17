/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_start
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void init_pos_button_txt(start_menu_t *start)
{
    start->pos_title.x = 1920/2 - 155;
    start->pos_title.y = 140;
    start->menu_buttons[0].sp_pos = (sfVector2f) {1920/2 - 142, 1080/4 + 50};
    start->menu_buttons[0].txt_pos = (sfVector2f) {1920/2 - 75, 1080/4 + 65};
    start->menu_buttons[1].sp_pos = (sfVector2f) {1920/2 - 142, 1080/4 + 200};
    start->menu_buttons[1].txt_pos = (sfVector2f) {1920/2 - 120, 1080/4 + 225};
    start->menu_buttons[2].sp_pos = (sfVector2f) {1920/2 - 142, 1080/4 + 350};
    start->menu_buttons[2].txt_pos = (sfVector2f) {1920/2 - 110, 1080/4 + 365};
    start->menu_buttons[3].sp_pos = (sfVector2f) {1920/2 - 142, 1080/4 + 500};
    start->menu_buttons[3].txt_pos = (sfVector2f) {1920/2 - 50, 1080/4 + 515};
    sfSprite_setPosition(start->menu_buttons[0].sprite, \
    start->menu_buttons[0].sp_pos);
    sfSprite_setPosition(start->menu_buttons[1].sprite, \
    start->menu_buttons[1].sp_pos);
    sfSprite_setPosition(start->menu_buttons[2].sprite, \
    start->menu_buttons[2].sp_pos);
    sfSprite_setPosition(start->menu_buttons[3].sprite, \
    start->menu_buttons[3].sp_pos);
}

static void init_text(start_menu_t *start, csfml_t *page)
{
    start->title = make_text(page->font_itim, "Lost RPG", \
        start->pos_title, 80);
    start->menu_buttons[0].text = make_text(page->font_itim, "START", \
    start->menu_buttons[0].txt_pos, 50);
    start->menu_buttons[1].text = make_text(page->font_itim, "HOW TO PLAY", \
    start->menu_buttons[1].txt_pos, 36);
    start->menu_buttons[2].text = make_text(page->font_itim, "SETTINGS", \
    start->menu_buttons[2].txt_pos, 48);
    start->menu_buttons[3].text = make_text(page->font_itim, "EXIT", \
    start->menu_buttons[3].txt_pos, 50);
}

static void init_sprite(start_menu_t *start, csfml_t *page)
{
    start->menu_buttons[0].sprite = make_sprite(page->button);
    start->menu_buttons[1].sprite = make_sprite(page->button);
    start->menu_buttons[2].sprite = make_sprite(page->button);
    start->menu_buttons[3].sprite = make_sprite(page->button);
    start->menu_buttons[0].sp_rect = (sfIntRect) {0, 0, 285, 110};
    start->menu_buttons[1].sp_rect = (sfIntRect) {0, 0, 285, 110};
    start->menu_buttons[2].sp_rect = (sfIntRect) {0, 0, 285, 110};
    start->menu_buttons[3].sp_rect = (sfIntRect) {0, 0, 285, 110};
}

void start_initialize(start_menu_t *start, csfml_t *page)
{
    start->menu_buttons = malloc(sizeof(button_t) * NB_START_MENU_B);
    init_sprite(start, page);
    init_pos_button_txt(start);
    init_text(start, page);
    start->menu_buttons[0].action = &action_start_button;
    start->menu_buttons[1].action = &action_howtoplay_button;
    start->menu_buttons[2].action = &action_settings_button;
    start->menu_buttons[3].action = &action_quit_button;
    start->menu_buttons[0].state = 0;
    start->menu_buttons[1].state = 0;
    start->menu_buttons[2].state = 0;
    start->menu_buttons[3].state = 0;
    start->menu_buttons[0].hover = &action_button_hover;
    start->menu_buttons[1].hover = &action_button_hover;
    start->menu_buttons[2].hover = &action_button_hover;
    start->menu_buttons[3].hover = &action_button_hover;
    start->back.tx_back = make_texture("./src/space.png");
    start->back.sp_back = make_sprite(start->back.tx_back);
    sfSprite_setTexture(start->back.sp_back, start->back.tx_back, sfFalse);
}