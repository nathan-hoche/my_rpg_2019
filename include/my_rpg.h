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
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define PLAYER_TEXTURE_1 "src/male.png"
#define PLAYER_TEXTURE_2 "src/female.png"

#define BUT_1_TXTR "src/button.png"
#define BUT_1_SIZ_X 285
#define BUT_1_SIZ_Y 110

#define BUT_2_TXTR "src/button_set.png"

#define FONT_1 "src/font_itim.ttf"
#define BACKGROUND_1 "src/space.png"

#define MAP_SP_SHEET "src/tile.png"

#define MAP_FILE_1 "map/map.txt"

#define MAP_GROUND_1 "src/grass.png"

#define DEFAULT_FX_LEVEL 60
#define DEFAULT_MUSIC_LEVEL 60

#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080

#define NB_SCENE 2
#define ID_CLOSE 0
#define ID_START_MENU 1
#define ID_GAME 2

#define NB_START_MENU_B 4

#define NB_SET_MENU_B 5

#define NB_TEXTURE_PLAYER 2

#define PLAYER_SP_SIZ_X 64
#define PLAYER_SP_SIZ_Y 64

#define MAP_BLOC_SIZE_X 32
#define MAP_BLOC_SIZE_Y 32


void game_menu(csfml_t *page);
void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);
void pause_menu(csfml_t *page);
void initialize_window(csfml_t *page);
void init_game_scene(game_scene_t *scene);
void map_display(game_scene_t *scene, sfSprite *tile, \
player_t *player, sfRenderWindow *window);
void init_player(player_t *player);
void init_destroy(player_t *player);
void clock_player_animation(player_t *player);
void destroy_player(player_t *player);
void player_orientation(sfEvent event, player_t *player);
int action_start_button(csfml_t *page);
int action_quit_button(csfml_t *page);
int action_settings_button(csfml_t *page);
int action_howtoplay_button(csfml_t *page);
void action_button_hover(button_t *button, csfml_t *core);
void check_buttons_hover(start_menu_t *start, csfml_t *page);
int button_obj_is_hover(button_t *button, sfRenderWindow *window);
void player_check_collision(player_t *player, sfVector2f pos_block);
void settings_initialize(settings_menu_t *set, csfml_t *page);
void free_game_ressources(game_menu_t *game);
void camera_fight_zoom(game_menu_t *game, csfml_t *page);

int action_plus_fx(csfml_t *page);
int action_minus_fx(csfml_t *page);
int action_plus_music(csfml_t *page);
int action_minus_music(csfml_t *page);
int action_return(csfml_t *page);
void settings(csfml_t *page);
void how_to_play(csfml_t *page);
void event_skin(csfml_t *page);
void skin(csfml_t *page);

#endif /* !MY_RPG_H_ */
