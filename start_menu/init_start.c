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
    start->menu_buttons[0].sp_pos = (sfVector2f) {1920/2 -142, 1080/2 -200};
    start->menu_buttons[0].txt_pos = (sfVector2f) {1920/2 -65, 1080/2 -185};
    start->back.pos_title.x = 1920/2 -150;
    start->back.pos_title.y = 140;
    start->menu_buttons[1].sp_pos = (sfVector2f) {1920/2 -142, 1080/2 -50};
    start->menu_buttons[1].txt_pos = (sfVector2f) {1920/2 -50, 1080/2 -35};
    sfSprite_setPosition(start->menu_buttons[0].sprite, start->menu_buttons[0].sp_pos);
    sfSprite_setPosition(start->menu_buttons[1].sprite, start->menu_buttons[1].sp_pos);
}

static void init_text(start_menu_t *start, csfml_t *page)
{
    start->back.title = make_text(page->font_itim, "Lost RPG", \
    start->back.pos_title, 70);
    start->menu_buttons[0].text = make_text(page->font_itim, "Start", \
    start->menu_buttons[0].txt_pos, 50);
    start->menu_buttons[1].text = make_text(page->font_itim, "Exit", \
    start->menu_buttons[1].txt_pos, 50);
}

static void init_sprite(start_menu_t *start, csfml_t *page)
{
    start->menu_buttons[0].sprite = make_sprite(page->button);
    start->menu_buttons[1].sprite = make_sprite(page->button);
}

void start_initialize(start_menu_t *start, csfml_t *page)
{
    start->menu_buttons = NULL;
    start->menu_buttons = malloc(sizeof(button_t) * NB_START_MENU_B);
    init_sprite(start, page);
    init_pos_button_txt(start);
    init_text(start, page);
    start->back.tx_back = make_texture("./src/space.png");
    start->back.sp_back = make_sprite(start->back.tx_back);
    sfSprite_setTexture(start->back.sp_back, start->back.tx_back, sfFalse);
}