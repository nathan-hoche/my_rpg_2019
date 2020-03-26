/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

//-> pause menu <-//
typedef struct pause_back_t {
    sfTexture *t_back;
    sfSprite *s_back;
}pause_back_t;

typedef struct pause_menu_t {
    pause_back_t back;
}pause_menu_t;

//-> game menu <-//
typedef struct game_back_t {
    sfTexture *t_back;
    sfSprite *s_back;
}game_back_t;

typedef struct game_menu_t {
    game_back_t back;
}game_menu_t;

//-> start menu <-//
typedef struct start_but_t {
    sfSprite *play_button;
    sfText *start_txt;
    sfSprite *exit_button;
    sfText *exit_txt;
    sfVector2f pos_but_play;
    sfVector2f pos_start_txt;
    sfVector2f pos_but_exit;
    sfVector2f pos_exit_txt;
}start_but_t;

typedef struct start_back_t {
    sfTexture *t_back;
    sfSprite *s_back;
    sfText *title;
    sfVector2f pos_title;
}start_back_t;

typedef struct start_menu_t {
    start_back_t back;
    start_but_t but;
}start_menu_t;

//-> principal info <-//
typedef struct csfml {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *button;
    sfVector2f size_button;
    sfFont *font_itim;
}csfml;

void initialize_window(csfml *page);
int game_menu(csfml *page);
int start_menu(csfml *page);
void start_initialize(start_menu_t *start, csfml *page);
int pause_menu(csfml *page);

#endif /* !MY_RPG_H_ */
