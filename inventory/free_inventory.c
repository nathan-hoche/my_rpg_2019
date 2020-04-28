/*
** EPITECH PROJECT, 2020
** free_inventory.c
** File description:
** free_inventory
*/

#include "my.h"
#include "struct.h"
#include "my_rpg.h"

void free_inventory(inventory_t *inventory)
{
    sfTexture_destroy(inventory->items.pants_tx);
    sfTexture_destroy(inventory->items.armor_tx);
    sfTexture_destroy(inventory->items.helmet_tx);
    sfTexture_destroy(inventory->items.shield_tx);
    sfTexture_destroy(inventory->items.sword_tx);
    sfTexture_destroy(inventory->tx_bar);
    sfSprite_destroy(inventory->items.pants_sp);
    sfSprite_destroy(inventory->items.armor_sp);
    sfSprite_destroy(inventory->items.helmet_sp);
    sfSprite_destroy(inventory->items.shield_sp);
    sfSprite_destroy(inventory->items.sword_sp);
    sfSprite_destroy(inventory->sp_bar);
    for (int i = 0; inventory->obj_name[i] != NULL; i++)
        free(inventory->obj_name[i]);
    free(inventory->obj_id);
}