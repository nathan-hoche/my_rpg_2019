/*
** EPITECH PROJECT, 2020
** initialize_npc_04.c
** File description:
** initialize_npc_04
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void set_sprite(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(53 * 32) + 16, (23 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 64, 64, 64};
    npc->sp = make_sprite(npc_txtr->sbire);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
}

static void set_dialog(npc_t *npc, npc_texture_t *npc_txtr)
{
    npc->talk_01 = NULL;
    npc->talk_01 = malloc(sizeof(char *) * 2);
    npc->talk_01[0] = my_strdup("What strenght ! Don't come near me !");
    npc->talk_01[1] = NULL;
    npc->action_patern = &patern_npc_04;
    npc->index_action = 0;
    npc->fighting.message_before = NULL;
    npc->fighting.message_before =  malloc(sizeof(char *) * 2);
    npc->fighting.message_before[0] = my_strdup("What are you doing here ?! \
    \nI'm gonna get you out of here !");
    npc->fighting.message_before[1] = NULL;
    npc->fighting.message_after = NULL;
    npc->fighting.message_after = malloc(sizeof(char *) * 2);
    npc->fighting.message_after[0] = my_strdup("Oh ...\nmy head ...");
    npc->fighting.message_after[1] = NULL;
}

void set_bad_npc_01(npc_t *npc, npc_texture_t *npc_txtr)
{
    set_sprite(npc, npc_txtr);
    set_dialog(npc, npc_txtr);
    npc->tmp_move = -1;
    npc->is_fighter = 1;
    npc->stats = (stats_t) {NULL, 15, 2, 12, 1};
    npc->state = 1;
    npc->talks_index = 1;
}