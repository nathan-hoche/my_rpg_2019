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

#define BASE_WIDTH (1920)
#define BASE_HEIGHT (1080)
#define NB_SCENE (2)
#define ID_CLOSE (0)
#define ID_START_MENU (1)
#define ID_GAME (2)
#define NB_START_MENU_B (2)

void game_menu(csfml_t *page);
void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);
void pause_menu(csfml_t *page);
void initialize_window(csfml_t *page);
void init_game_scene(game_scene_t *scene);
void map_display(game_scene_t *scene, sfSprite *tile, sfRenderWindow *window);
void init_player(player_t *player);
void init_destroy(player_t *player);
void clock_player_animation(player_t *player);
void destroy_player(player_t *player);
void player_orientation(sfEvent event, player_t *player);

#endif /* !MY_RPG_H_ */
