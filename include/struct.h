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

typedef struct csfml_s csfml_t;
typedef struct fight_scene_s fight_scene_t;

typedef struct basic_text_s {
    sfText *text;
    sfVector2f pos;
}basic_text_t;

typedef struct background_s {
    sfTexture *tx_back;
    sfSprite *sp_back;
}background_t;

//-> BASIC OBJECT BUTTON <-/////////////////////////////

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
}pause_menu_t;

//-> GAME SCENE <-///////////////////////////////

typedef struct game_scene_s {
    char *map_layer01_file;
    char *map_layer02_file;
    char *map_layer01;
    char *map_layer02;
    sfVector2f starting_pos;
}game_scene_t;

typedef struct game_menu_s {
    int on_fight;
    sfClock *cam_clock;
    game_scene_t first_scene;
    sfTexture *texture_tile;
    sfSprite *tile;
    sfTexture *grass;
    sfSprite *back_grass;
}game_menu_t;


//-> FIGHT SCENE <-///////////////////////////////

typedef struct life_area_s {
    sfText *name;
    sfText *life_txt;
    sfText *life_val;
}life_area_t;

typedef struct stats_area_s {
    sfText *name;
    sfText *atk_txt;
    sfText *atk_val;
    sfText *shld_txt;
    sfText *shld_val;
}stats_area_t;

typedef struct fight_buttons_s {
    sfTexture *texture;
    sfSprite *button_atk;
    sfVector2f pos_butt_atk;
    sfVector2f size_butt_atk;
    sfText *txt_atk;
    sfSprite *button_def;
    sfVector2f pos_butt_def;
    sfVector2f size_butt_def;
    sfText *txt_def;
}fight_buttons_t;

typedef struct info_area_s {
    life_area_t player_life_area;
    life_area_t enemy_life_area;
    stats_area_t player_stats_area;
    stats_area_t enemy_stats_area;
    sfText *txt_wait;
}info_area_t;

typedef struct stats_s {
    char hp;
    int atk;
    int armor;
    int speed;
}stats_t;

typedef struct fighter_s {
    sfSprite *sp;
    sfVector2f pos;
    stats_t stats;
    sfBool def;
}fighter_t;

typedef struct fight_scene_s {
    char turn_state;
    char atk_step;
    char updater;
    background_t back;
    info_area_t info_area;
    fight_buttons_t fight_buttons;
    fighter_t enemy;
    fighter_t player;
    sfClock *clock_move;
    sfClock *clock_atk;
    sfSprite *sword_slash;
    sfIntRect sword_slash_rect;
    sfSprite *shield;
}fight_scene_t;


//-> START SCENE <-//////////////////////////////

typedef struct start_menu_s {
    background_t back;
    button_t *menu_buttons;
    sfText *title;
    sfVector2f pos_title;
}start_menu_t;


//-> HOW TO PLAY MENU <-/////////////////////////

typedef struct htp_menu_t {
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
}skin_menu_t;

//-> PRINCIPAL INFORMATION <-////////////////////

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

typedef struct views_s {
    sfView const *default_view;
    sfView *default_player_view;
    sfView *actual_view;
}views_t;

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
}csfml_t;

#endif /* !SCENE_H_ */
