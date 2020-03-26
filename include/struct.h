/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct csfml_s csfml_t; // For implicit declaration

//-> scene tab <-//
typedef struct scene_tab_t {
    int id_scene;
    void (* scene)(csfml_t *);
}scene_tab_t;

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

//-> simple button struct <-//
typedef struct button_s {
    sfSprite *sprite;
    sfVector2f sp_pos;
    sfIntRect sp_rect;
    sfText *text;
    sfVector2f txt_pos;
    unsigned char state;
    void (* action)(csfml_t *);
}button_t;

typedef struct start_back_t {
    sfTexture *tx_back;
    sfSprite *sp_back;
    sfText *title;
    sfVector2f pos_title;
}start_back_t;

typedef struct start_menu_t {
    start_back_t back;
    button_t *menu_buttons;
}start_menu_t;

//-> principal info <-//
typedef struct csfml_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *button;
    sfVector2f size_button;
    sfFont *font_itim;
    int act_scene;
}csfml_t;

#endif /* !SCENE_H_ */
