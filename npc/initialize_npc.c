/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void set_sbire_npc(npc_t *npc)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(20 * 32) + 16, (20 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->tx = make_texture(NPC_01_TXTR);
    npc->sp = make_sprite(npc->tx);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
    npc->talk_1 = NULL;
    npc->is_fighter = 0;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->state = 1;
}

static void set_bad_npc(npc_t *npc)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(15 * 32) + 16, (15 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->tx = make_texture(NPC_01_TXTR);
    npc->sp = make_sprite(npc->tx);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->is_fighter = 1;
    npc->stats = (stats_t) {NULL, 15, 2, 12, 1};
    npc->state = 1;
    npc->talk_1 =  malloc(sizeof(char *) * 3);
    npc->talk_1[0] = my_strdup("Oh ! Bonjour, c'est la premiere fois que \n je vous vois ici ...");
    npc->talk_1[1] = my_strdup("bug.");
    npc->talk_1[2] = NULL;

/*     npc->fighting.message_before = NULL;
    npc->fighting.message_after = NULL; */


    npc->fighting.message_before =  malloc(sizeof(char *) * 3);
    npc->fighting.message_before[0] = my_strdup("MESSAGE BEFORE");
    npc->fighting.message_before[1] = my_strdup(".1.");
    npc->fighting.message_before[2] = NULL;

    npc->fighting.message_after =  malloc(sizeof(char *) * 3);
    npc->fighting.message_after[0] = my_strdup("MESSAGE AFTER");
    npc->fighting.message_after[1] = my_strdup(".2.");
    npc->fighting.message_after[2] = NULL;
}

void initialize_npc(game_menu_t *game)
{
    game->npc = malloc(sizeof(npc_t) * 2);
    set_good_npc(&game->npc[0]);
    set_bad_npc(&game->npc[1]);
}