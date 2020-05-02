/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void set_good_npc(npc_t *npc)
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
    npc->inter_talk_1 = &manage_action_message;
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
    npc->inter_talk_1 = &manage_action_message;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->is_fighter = 1;
    npc->stats = (stats_t) {"Bad boy", 15, 2, 12, 1};
    npc->state = 1;
}

void set_npc(game_menu_t *game)
{
    game->npc = malloc(sizeof(npc_t) * 2);
    set_good_npc(&game->npc[0]);
    set_bad_npc(&game->npc[1]);
}