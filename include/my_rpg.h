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
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define PLAYER_TEXTURE_1 "src/male.png"
#define PLAYER_TEXTURE_2 "src/female.png"

#define BUT_1_TXTR "src/button.png"
#define BUT_1_SIZ_X (285)
#define BUT_1_SIZ_Y (110)

#define BUT_2_TXTR "src/button_set.png"

#define FONT_1 "src/font_itim.ttf"
#define BACKGROUND_1 "src/space.png"

#define MAP_SP_SHEET "src/tile.png"

#define MAP_L01_FILE "map/map_layer01.txt"
#define MAP_L02_FILE "map/map_layer02.txt"

#define MAP_GROUND_1 "src/grass.png"

#define FIGHT_BACK_1 "src/set_fight/background.png"

#define PLAYER_SPAWN_POS_X (0)
#define PLAYER_SPAWN_POS_Y (0)

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

#define CAM_DEFAULT_ZOOM (0.6)

#define FIGHT_BUTTONS_TEXTR "src/set_fight/buttons.png"

void initialize_window(csfml_t *page);
void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);

void game_menu(csfml_t *page);
void free_game_ressources(game_menu_t *game);
void pause_menu(csfml_t *page);
void init_game_scene(game_scene_t *scene);

void map_display(char *map, game_scene_t *scene, sfSprite *tile, \
csfml_t *general);

void init_player(player_t *player);
void clock_player_animation(player_t *player);
void destroy_player(player_t *player);
void player_orientation(sfEvent event, player_t *player);
void player_check_collision(player_t *player, sfVector2f pos_block);

int action_start_button(csfml_t *page);
int action_quit_button(csfml_t *page);
int action_settings_button(csfml_t *page);
int action_howtoplay_button(csfml_t *page);

void action_button_hover(button_t *button, csfml_t *core);
void check_buttons_hover(start_menu_t *start, csfml_t *page);
int button_obj_is_hover(button_t *button, sfRenderWindow *window);

void settings(csfml_t *page);
void settings_initialize(settings_menu_t *set, csfml_t *page);
int action_plus_fx(csfml_t *page);
int action_minus_fx(csfml_t *page);
int action_plus_music(csfml_t *page);
int action_minus_music(csfml_t *page);
int action_return(csfml_t *page);

void how_to_play(csfml_t *page);

void start_fight(game_menu_t *game, csfml_t *page);
int camera_fight_zoom(game_menu_t *game, csfml_t *page);

void fight_initialize(fight_scene_t *fight, csfml_t *general);
void fight_core(csfml_t *general, game_menu_t *game);
void fight_destroy(fight_scene_t *fight);

void event_skin(csfml_t *page);

void skin(csfml_t *page);

void fight_core(csfml_t *page, game_menu_t *game);
void display_infos_areas(fight_scene_t *fight, sfRenderWindow *window);
void turn_core(fight_scene_t *fight, sfRenderWindow *window);
void initialize_areas(csfml_t *general, fight_scene_t *fight);
void display_stats_valors(info_area_t *area, stats_t *player, stats_t *enemy);
void fight_attack_animation(fighter_t *striker, fighter_t *target, 
fight_scene_t *fight, csfml_t *general);

#endif /* !MY_RPG_H_ */
