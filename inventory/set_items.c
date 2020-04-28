/*
** EPITECH PROJECT, 2020
** set_items.c
** File description:
** set_items
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void display_items(sfRenderWindow *window, items_t *items)
{
    sfRenderWindow_drawSprite(window, items->sword_sp, NULL);
    sfRenderWindow_drawSprite(window, items->shield_sp, NULL);
    sfRenderWindow_drawSprite(window, items->helmet_sp, NULL);
    sfRenderWindow_drawSprite(window, items->armor_sp, NULL);
    sfRenderWindow_drawSprite(window, items->pants_sp, NULL);
}

void initialize_items(items_t *items)
{
    items->sword_tx = make_texture(SWORD_FILE);
    items->sword_sp = make_sprite(items->sword_tx);
    items->shield_tx = make_texture(SHIELD_FILE);
    items->shield_sp = make_sprite(items->shield_tx);
    items->helmet_tx = make_texture(HELMET_FILE);
    items->helmet_sp = make_sprite(items->helmet_tx);
    items->armor_tx = make_texture(ARMOR_FILE);
    items->armor_sp = make_sprite(items->armor_tx);
    items->pants_tx = make_texture(PANTS_FILE);
    items->pants_sp = make_sprite(items->pants_tx);
}