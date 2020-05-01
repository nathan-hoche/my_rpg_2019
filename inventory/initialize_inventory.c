/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** create_inventory
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

void set_inventory_pos(csfml_t *general, inventory_t *inventory)
{
    sfVector2f pos;

    pos.x = general->player.pos_px.x;
    pos.y = general->player.pos_px.y;
    pos.x -= 170;
    pos.y += 180;
    sfSprite_setPosition(inventory->sp_bar, pos);
    sfSprite_setPosition(inventory->items.sword_sp, \
    (sfVector2f) {pos.x + SWORD_POS_X, pos.y + SWORD_POS_Y});
    sfSprite_setPosition(inventory->items.shield_sp, \
    (sfVector2f) {pos.x + SHIELD_POS_X, pos.y + SHIELD_POS_Y});
    sfSprite_setPosition(inventory->items.helmet_sp, \
    (sfVector2f) {pos.x + HELMET_POS_X, pos.y + HELMET_POS_Y});
    sfSprite_setPosition(inventory->items.armor_sp, \
    (sfVector2f) {pos.x + ARMOR_POS_X, pos.y + ARMOR_POS_Y});
    sfSprite_setPosition(inventory->items.pants_sp, \
    (sfVector2f) {pos.x + PANTS_POS_X, pos.y});
}

void manage_inventory_event(csfml_t *general, inventory_t *inventory)
{
    if (general->event.key.code == sfKeyI && \
    general->event.type == sfEvtKeyPressed && inventory->status == 0)
        inventory->status = 1;
    else if (general->event.key.code == sfKeyI && general->event.type \
    == sfEvtKeyPressed)
        inventory->status = 0;
}

static void put_obj_name(inventory_t *inventory, FILE *fp, csfml_t *general)
{
    char *buf = NULL;
    char *line = NULL;
    size_t len = 0;
    __ssize_t read;

    inventory->stats.stat = malloc(sizeof(int) * STAT_DATA);
    inventory->stats.stat[0] = 0;
    inventory->stats.stat[1] = 0;
    inventory->stats.stat[2] = 0;
    read = getline(&buf, &len, fp);
    for (int i = 0; read != -1; i++) {
        read = getline(&line, &len, fp);
        if (read != -1) {
            buf = initialize_stats(inventory, buf, line, general);
        }
    }
    initialize_texts(&inventory->stats, general);
    inventory->obj_name = my_str_to_word_array(buf, '\n');
    free(line);
    free(buf);
    fclose(fp);
}

static int *put_obj_id(int *id_inventory, FILE *fp)
{
    int id = 0;
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, fp) == -1)
        return (NULL);
    id = my_getnbr(line);
    for (int i = 0; i < INVENTORY_ID_SIZE; i++) {
        id_inventory[i] = id;
        id += 1;
    }
    free(line);
    return (id_inventory);
}

int initialize_inventory(inventory_t *inventory, csfml_t *general)
{
    items_t items;
    FILE *fp;

    fp = fopen(CONFIG_INVENTORY_FILE, "r");
    if (!fp)
        return (84);
    inventory->obj_id = malloc(sizeof(int) * INVENTORY_ID_SIZE);
    if (!inventory->obj_id)
        return (84);
    inventory->obj_id = put_obj_id(inventory->obj_id, fp);
    put_obj_name(inventory, fp, general);
    inventory->tx_bar = make_texture(INVENTORY_FILE);
    inventory->sp_bar = make_sprite(inventory->tx_bar);
    inventory->status = 0;
    initialize_items(&inventory->items);
    return (0);
}