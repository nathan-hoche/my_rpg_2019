/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg structs
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct items_s {
    sfTexture *sword_tx;
    sfSprite *sword_sp;
    sfTexture *shield_tx;
    sfSprite *shield_sp;
    sfTexture *helmet_tx;
    sfSprite *helmet_sp;
    sfTexture *armor_tx;
    sfSprite *armor_sp;
    sfTexture *pants_tx;
    sfSprite *pants_sp;
}items_t;

typedef struct inventory_s {
    int *obj_id;
    char **obj_name;
    int status;
    sfTexture *tx_bar;
    sfSprite *sp_bar;
    items_t items;
}inventory_t;

typedef struct csfml_s csfml_t;

typedef struct basic_text_s {
    sfText *text;
    sfVector2f pos;
}basic_text_t;

typedef struct background_s {
    sfTexture *tx_back;
    sfSprite *sp_back;
}background_t;

//-> BASIC BUTTON <-/////////////////////////////

typedef struct button_s {
    sfSprite *sprite;
    sfVector2f sp_pos;
    sfIntRect sp_rect;
    sfText *text;
    sfVector2f txt_pos;
    unsigned char state;
    int (* action)(csfml_t *);
    void (* hover)(struct button_s *, csfml_t *);
}button_t;

//-> SCENE TAB <-////////////////////////////////

typedef struct scene_tab_s {
    int id_scene;
    void (* scene)(csfml_t *);
}scene_tab_t;

//-> PAUSE MENU <-///////////////////////////////

typedef struct pause_menu_s {
    background_t back;
    sfSprite *button;
    sfText *resume;
    sfText *htp;
    sfText *settings;
    sfText *exit;
}pause_menu_t;

//-> GAME SCENE <-///////////////////////////////

typedef struct game_scene_s {
    int **view_dist;
    char *map_layer01_file;
    char *map_layer02_file;
    char **map_layer01;
    char **map_layer02;
    sfVector2f starting_pos;
}game_scene_t;

typedef struct game_menu_s {
    int on_fight;
    sfClock *cam_clock;
    game_scene_t game_scene;
    sfTexture *texture_tile;
    sfSprite *tile;
    sfTexture *grass;
    sfSprite *back_grass;
    inventory_t inventory;
}game_menu_t;

//-> START SCENE <-//////////////////////////////

typedef struct start_menu_s {
    background_t back;
    button_t *menu_buttons;
    sfText *title;
    sfVector2f pos_title;
}start_menu_t;

//-> HOW TO PLAY MENU <-/////////////////////////

typedef struct htp_menu_t {
    sfTexture *htp_texture;
    sfSprite *exit_button;
    sfSprite *htp;
    sfText *exit;
    sfVector2f pos_but;
    background_t back;
}htp_menu_t;

//-> SETTINGS MENU <-////////////////////////////

typedef struct settings_s {
    float fx_lvl;
    float music_lvl;
}settings_t;

typedef struct settings_menu_s {
    background_t back;
    button_t *buttons;
    basic_text_t txt_lvl_music;
    basic_text_t txt_lvl_fx;
    basic_text_t txt_music;
    basic_text_t txt_fx;
}settings_menu_t;

//-> SKIN MENU <-////////////////////////////////

typedef struct skin_menu_t {
    background_t back;
    sfSprite *female;
    sfSprite *male;
    sfText *title;
}skin_menu_t;

//-> PRINCIPAL INFORMATION <-////////////////////

typedef struct player_t {
    sfTexture *texture_male;
    sfTexture *texture_female;
    sfSprite *player;
    sfIntRect player_rect;
    sfClock *animation;
    sfClock *movement;
    sfVector2f move_direction;
    int gender;
    int on_move;
    int on_anim;
    sfVector2i pos_cart;
    sfVector2i pos_px;
    sfVector2i pos_traj;
}player_t;

typedef struct views_s {
    sfView const *default_view;
    sfView *default_player_view;
    sfView *actual_view;
}views_t;

typedef struct music_s {
    sfMusic *menu;
    int music_played;
    sfSoundBuffer *sound_but_buf;
    sfSound *sound_but;
}music_t;

typedef struct csfml_s {
    sfVideoMode mode;
    views_t views;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *button_1;
    sfTexture *button_2;
    sfVector2f size_button;
    sfFont *font_itim;
    player_t player;
    int act_scene;
    settings_t settings;
    music_t music;
}csfml_t;

#endif /* !SCENE_H_ */
