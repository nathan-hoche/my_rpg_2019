/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_start
*/

#include "../include/my_rpg.h"
#include "../include/my.h"

static void init_pos_button_txt(start_menu_t *start)
{
    start->but.pos_but_play.x = 1920/2 -142;
    start->but.pos_but_play.y = 1080/2 -200;
    start->but.pos_start_txt.x = 1920/2 -65;
    start->but.pos_start_txt.y = 1080/2 -185;
    start->back.pos_title.x = 1920/2 -150;
    start->back.pos_title.y = 140;
    start->but.pos_but_exit.x = 1920/2 -142;
    start->but.pos_but_exit.y = 1080/2 -50;
    start->but.pos_exit_txt.x = 1920/2 -50;
    start->but.pos_exit_txt.y = 1080/2 -35;
}

static void init_text(start_menu_t *start, csfml *page)
{
    start->back.title = make_text(page->font_itim, "Lost RPG", \
    start->back.pos_title, 70);
    start->but.start_txt = make_text(page->font_itim, "Start", \
    start->but.pos_start_txt, 50);
    start->but.exit_txt = make_text(page->font_itim, "Exit", \
    start->but.pos_exit_txt, 50);
}

static void init_sprite(start_menu_t *start, csfml *page)
{
    start->back.s_back = make_sprite(start->back.t_back);
    start->but.play_button = make_sprite(page->button);
    start->but.exit_button = make_sprite(page->button);
    sfSprite_setPosition(start->but.play_button, start->but.pos_but_play);
    sfSprite_setPosition(start->but.exit_button, start->but.pos_but_exit);
}

void start_initialize(start_menu_t *start, csfml *page)
{
    init_pos_button_txt(start);
    init_text(start, page);
    start->back.t_back = make_texture("src/space.png");
    init_sprite(start, page);
}