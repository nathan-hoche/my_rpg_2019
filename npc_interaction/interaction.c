/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void set_npc_interaction(npc_t *npc)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(20 * 32) + 16, (20 * 32) + 16};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->tx = make_texture(NPC_01_TXTR);
    npc->sp = make_sprite(npc->tx);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
}