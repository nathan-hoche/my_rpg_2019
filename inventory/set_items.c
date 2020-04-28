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

static void set_items_pos(items_t *items)
{
    sfSprite_setPosition(items->sword_sp, (sfVector2f) {775, 960});
    sfSprite_setPosition(items->shield_sp, (sfVector2f) {835, 970});
    sfSprite_setPosition(items->helmet_sp, (sfVector2f) {883, 965});
    sfSprite_setPosition(items->armor_sp, (sfVector2f) {930, 965});
    sfSprite_setPosition(items->pants_sp, (sfVector2f) {985, 963});
}

void initialize_items(items_t *items)
{
    items->sword_tx = make_texture("src/items/weapons/sword_start.png");
    items->sword_sp = make_sprite(items->sword_tx);
    items->shield_tx = make_texture("src/items/armor/shield_one.png");
    items->shield_sp = make_sprite(items->shield_tx);
    items->helmet_tx = make_texture("src/items/armor/helmet_one.png");
    items->helmet_sp = make_sprite(items->helmet_tx);
    items->armor_tx = make_texture("src/items/armor/bust_two.png");
    items->armor_sp = make_sprite(items->armor_tx);
    items->pants_tx = make_texture("src/items/armor/leggings_two.png");
    items->pants_sp = make_sprite(items->pants_tx);
    set_items_pos(items);
}