/*
** EPITECH PROJECT, 2020
** set_outro.c
** File description:
** set_outro
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

void set_outro(sfRenderWindow *window, game_menu_t *game)
{
    sfSprite_setScale(game->outro.memory_sp, (sfVector2f) {1.6, 1.6});
    sfRenderWindow_drawSprite(window, game->outro.outro_sp, NULL);
    sfRenderWindow_drawSprite(window, game->outro.memory_sp, NULL);
}