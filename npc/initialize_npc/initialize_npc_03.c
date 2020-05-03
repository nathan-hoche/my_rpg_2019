/*
** EPITECH PROJECT, 2020
** initialize_npc_03.c
** File description:
** initialize npc 03
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void set_sprite(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(37 * 32) + 16, (30 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->sp = make_sprite(npc_txtr->villager_03);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
}

void set_good_npc_03(npc_t *npc, npc_texture_t *npc_txtr)
{
    set_sprite(npc, npc_txtr);

    npc->is_fighter = 0;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->state = 1;
    npc->action_patern = NULL;
    npc->action_patern = NULL;
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 =  malloc(sizeof(char *) * 5);
    npc->talk_01[0] = my_strdup("Who are you ? I ve never seen you before.\n\
    Life is very sad in this world, \nbrigands have struck again");
    npc->talk_01[1] = my_strdup("if only someone could protect us ...");
    npc->talk_01[2] = NULL;
}