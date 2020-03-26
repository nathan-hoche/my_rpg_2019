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
#include "my_rpg.h"
#include "struct.h"

#define BASE_WIDTH 1920 // Basic window width size
#define BASE_HEIGHT 1080 // Basic window width size
#define NB_SCENE 2 // Number of scene
#define ID_CLOSE 0  // ID for close scene
#define ID_START_MENU 1  // ID for start menu
#define ID_GAME 2  // ID for game
#define NB_START_MENU_B 2 // NB of button on start menu

void game_menu(csfml_t *page);
void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);
void pause_menu(csfml_t *page);
void initialize_window(csfml_t *page);

#endif /* !MY_RPG_H_ */
