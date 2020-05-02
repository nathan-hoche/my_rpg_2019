/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop the game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int is_behind_npc(player_t *player, npc_t *npc)
{
    if ((player->pos_traj.x == npc->pos_cart.x && \
        player->pos_traj.y == npc->pos_cart.y - 1) ||
        (player->pos_traj.x - 1 == npc->pos_cart.x && \
        player->pos_traj.y == npc->pos_cart.y - 1) ||
        (player->pos_traj.x + 1 == npc->pos_cart.x && \
        player->pos_traj.y == npc->pos_cart.y - 1))
        return (1);
    return (0);
}

void display_player_with_entities(csfml_t *general, game_menu_t *game)
{
    int pos_en = -1;

    for (int i = 0; i < 2; i++) {
        if (game->npc[i].state != 0 && \
        is_behind_npc(&general->player, &game->npc[i]) == 1)
            pos_en = i;
    }
    for (int i = 0; i < 2; i++) {
        if (i != pos_en)
            sfRenderWindow_drawSprite(general->window, game->npc[i].sp, NULL);
        if (game->on_msg == 0 && game->on_fight == 0)
            manage_npc_actions(&game->npc[i], &general->player);
    }
    sfRenderWindow_drawSprite(general->window, general->player.player, NULL);
    if (pos_en != -1)
        sfRenderWindow_drawSprite(general->window, game->npc[pos_en].sp, NULL);
}