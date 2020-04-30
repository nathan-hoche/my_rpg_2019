/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** create_inventory
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

void display_inventory(csfml_t *general, game_menu_t *game)
{
    if (game->inventory.status == 1) {
        set_inventory_pos(general, &game->inventory);
        sfRenderWindow_drawSprite(general->window, \
            game->inventory.sp_bar, NULL);
        display_items(general->window, &game->inventory.items);
    }
}