/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg prototypes
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define PLAYER_TEXTURE_1 "src/male.png"
#define PLAYER_TEXTURE_2 "src/female.png"

#define MUSIC_MENU "src/menu.ogg"
#define MUSIC_MENU_PLAY (1)
#define CLICK_SOUND "src/click.ogg"

#define BUT_1_TXTR "src/button.png"
#define BUT_1_SIZ_X (285)
#define BUT_1_SIZ_Y (110)

#define BUT_2_TXTR "src/button_set.png"

#define FONT_1 "src/font_itim.ttf"
#define BACKGROUND_1 "src/space.png"
#define BACKGROUND_2 "src/island.jpg"

#define MAP_SP_SHEET "src/tile.png"

#define MAP_L01_FILE "map/map_layer01.txt"
#define MAP_L02_FILE "map/map_layer02.txt"

#define MAP_GROUND_1 "src/water.jpg"

#define CONFIG_INVENTORY_FILE "src/config.txt"

#define INVENTORY_FILE "src/inventory.png"
#define SWORD_FILE "src/items/weapons/sword_start.png"
#define SHIELD_FILE "src/items/armor/shield_start.png"
#define HELMET_FILE "src/items/armor/helmet_start.png"
#define ARMOR_FILE "src/items/armor/bust_start.png"
#define PANTS_FILE "src/items/armor/pants_start.png"

#define INTRO_BACKGROUND "src/intro.png"

#define DEFAULT_FX_LEVEL (60)
#define DEFAULT_MUSIC_LEVEL (60)

#define BASE_WIDTH (1920)
#define BASE_HEIGHT (1080)

#define NB_SCENE (2)
#define ID_CLOSE (0)
#define ID_START_MENU (1)
#define ID_GAME (2)

#define NB_START_MENU_B (4)

#define NB_SET_MENU_B (5)

#define NB_TEXTURE_PLAYER (2)

#define PLAYER_SP_SIZ_X (64)
#define PLAYER_SP_SIZ_Y (64)

#define BLOCK_SIZE_X (32)
#define BLOCK_SIZE_Y (32)

#define CAM_DEFAULT_ZOOM (0.48)

#define INVENTORY_ID_SIZE (7)

#define SWORD_POS_X (5)
#define SWORD_POS_Y (2)
#define SHIELD_POS_X (65)
#define SHIELD_POS_Y (6)
#define HELMET_POS_X (115)
#define HELMET_POS_Y (4)
#define ARMOR_POS_X (162)
#define ARMOR_POS_Y (1)
#define PANTS_POS_X (216)

void game_menu(csfml_t *page);
void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);
void pause_menu(csfml_t *page);
void initialize_window(csfml_t *page);
void init_game_scene(game_scene_t *scene);
void init_player(player_t *player);
void init_game_player(player_t *player, game_scene_t *game_scene);
void init_destroy(player_t *player);
void destroy_player(player_t *player);
void player_orientation(sfEvent event, player_t *player, game_menu_t *game);
int action_start_button(csfml_t *page);
int action_quit_button(csfml_t *page);
int action_settings_button(csfml_t *page);
int action_howtoplay_button(csfml_t *page);
void action_button_hover(button_t *button, csfml_t *core);
void check_buttons_hover(start_menu_t *start, csfml_t *page);
int button_obj_is_hover(button_t *button, sfRenderWindow *window);
void settings_initialize(settings_menu_t *set, csfml_t *page);
void free_game_ressources(game_menu_t *game);
void camera_fight_zoom(game_menu_t *game, csfml_t *page);
int **display_optimization(char **map, player_t *playr, int **view_dist);

void change_volume(music_t *music);
int action_plus_fx(csfml_t *page);
int action_minus_fx(csfml_t *page);
int action_plus_music(csfml_t *page);
int action_minus_music(csfml_t *page);
int action_return(csfml_t *page);
void settings(csfml_t *page);
void how_to_play(csfml_t *page);
int event_skin(csfml_t *page);
void skin(csfml_t *page);
int pause_check_button(csfml_t *page, pause_menu_t *pause);

void fight_core(csfml_t *page, game_menu_t *game);

void display_map_core(game_menu_t *game, csfml_t *general);
void player_core(csfml_t *general, game_menu_t *game);
void camera_view(game_menu_t *game, csfml_t *page);
int player_collision_core(int key, player_t *player, game_menu_t *game);

int initialize_inventory(inventory_t *inventory);
void initialize_items(items_t *items);
void manage_inventory_event(csfml_t *page, inventory_t *inventory);
void display_items(sfRenderWindow *window, items_t *items);
void free_inventory(inventory_t *inventory);
void set_inventory_pos(csfml_t *page, inventory_t *inventory);
void display_inventory(csfml_t *general, game_menu_t *game);

void begin_intro(intro_t *intro);
void display_intro(sfRenderWindow *window, game_menu_t *game);
#endif /* !MY_RPG_H_ */