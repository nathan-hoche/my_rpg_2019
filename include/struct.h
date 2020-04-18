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
typedef struct scene_tab_s {
    int id_scene;
    void (* scene)(csfml_t *);
}scene_tab_t;

//-> pause menu <-//
typedef struct background_s {
    sfTexture *tx_back;
    sfSprite *sp_back;
}background_t;

typedef struct pause_menu_s {
    background_t back;
}pause_menu_t;

//-> game menu <-//
typedef struct game_scene_s {
    char *map_file;
    char *map;
    sfVector2f starting_pos;
}game_scene_t;

typedef struct game_menu_s {
    game_scene_t first_scene;
    sfTexture *texture_tile;
    sfSprite *tile;
    sfTexture *grass;
    sfSprite *back_grass;
}game_menu_t;

//-> simple button struct <-//
typedef struct button_s button_t;

typedef struct button_s {
    sfSprite *sprite;
    sfVector2f sp_pos;
    sfIntRect sp_rect;
    sfText *text;
    sfVector2f txt_pos;
    unsigned char state;
    void (* action)(csfml_t *);
    void (* hover)(button_t *, csfml_t *);
}button_t;

typedef struct start_menu_s {
    background_t back;
    button_t *menu_buttons;
    sfText *title;
    sfVector2f pos_title;
}start_menu_t;

//-> how to play <-//

typedef struct htp_menu_t {
    background_t back;
}htp_menu_t;

//-> settings <-//

typedef struct settings_s {
    float fx_lvl;
    float music_lvl;
}settings_t;

typedef struct settings_menu_s {
    background_t back;
}settings_menu_t;

//-> skin <-//

typedef struct skin_menu_t {
    background_t back;
}skin_menu_t;

//-> principal info <-//


typedef struct player_t {
    sfTexture *texture_male;
    sfTexture *texture_female;
    sfSprite *player;
    sfIntRect player_rect;
    sfClock *animation;
    sfVector2f move_direction;
    int nb_move;
    int move_ways;
    int collision;
}player_t;

typedef struct csfml_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *button;
    sfVector2f size_button;
    sfFont *font_itim;
    player_t player;
    int act_scene;
    settings_t settings;
}csfml_t;

#endif /* !SCENE_H_ */
