/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free game ressources
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void free_game_ressources(game_menu_t *game)
{
    free_inventory(&game->inventory);
    sfTexture_destroy(game->grass);
    sfTexture_destroy(game->texture_tile);
    sfSprite_destroy(game->tile);
    sfSprite_destroy(game->back_grass);
}