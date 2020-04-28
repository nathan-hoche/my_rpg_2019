/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** create_inventory
*/

#include "my_rpg.h"
#include "struct.h"
#include "my.h"

void manage_inventory_event(csfml_t *page, inventory_t *inventory)
{
    if (page->event.key.code == sfKeyI && page->event.type == sfEvtKeyPressed \
    && inventory->status == 0)
        inventory->status = 1;
    else if (page->event.key.code == sfKeyI && page->event.type \
    == sfEvtKeyPressed)
        inventory->status = 0;
}

static void put_obj_name(inventory_t *inventory, FILE *fp)
{
    char *buf = NULL;
    char *line = NULL;
    size_t len = 0;
    __ssize_t read;

    read = getline(&buf, &len, fp);
    while (read != -1) {
        read = getline(&line, &len, fp);
        if (read != -1)
            buf = my_strcat(buf, line);
    }
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

int initialize_inventory(inventory_t *inventory)
{
    items_t items;
    FILE *fp;

    fp = fopen("src/config.txt", "r");
    if (!fp)
        return (84);
    inventory->obj_id = malloc(sizeof(int) * INVENTORY_ID_SIZE);
    if (!inventory->obj_id)
        return (84);
    inventory->obj_id = put_obj_id(inventory->obj_id, fp);
    put_obj_name(inventory, fp);
    inventory->tx_bar = make_texture("src/inventory.png");
    inventory->sp_bar = make_sprite(inventory->tx_bar);
    inventory->status = 0;
    sfSprite_setPosition(inventory->sp_bar, (sfVector2f) {770, 965});
    initialize_items(&inventory->items);
    return (0);
}