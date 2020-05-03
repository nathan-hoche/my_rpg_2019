/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void set_good_npc_01(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(20 * 32) + 16, (20 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->sp = make_sprite(npc_txtr->villager_01);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
    npc->is_fighter = 0;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->state = 1;
    npc->action_patern = &partern_npc_01;
    npc->talks_index = 0;
    npc->talks =  malloc(sizeof(char **) * 2);
    npc->talks[0] = malloc(sizeof(char *) * 2);
    npc->talks[0][0] = my_strdup("Brigands have ravaged everything ! \nMy crops are ruined !");
    npc->talks[0][1] = NULL;
    npc->talks[1] = NULL;
}

static void set_good_npc_02(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(35 * 32) + 16, (20 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->sp = make_sprite(npc_txtr->villager_02);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
    npc->is_fighter = 0;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->state = 1;
    npc->action_patern = &partern_npc_02;
    npc->talks_index = 0;
    npc->talks =  malloc(sizeof(char **) * 2);
    npc->talks[0] = malloc(sizeof(char *) * 2);
    npc->talks[0][0] = my_strdup("They killed my goats while I looked on ! \n ... I have nothing left to lose ... ");
    npc->talks[0][1] = NULL;
    npc->talks[1] = NULL;
}

static void set_bad_npc_01(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(15 * 32) + 16, (15 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 0, 64, 64};
    npc->sp = make_sprite(npc_txtr->sbire);
    sfSprite_setTextureRect(npc->sp, npc->tx_rect);
    sfSprite_setOrigin(npc->sp, (sfVector2f) {32, 48});
    sfSprite_setPosition(npc->sp, npc->pos_px);
    npc_pos = sfSprite_getPosition(npc->sp);
    npc->pos_cart.x = npc_pos.x / 32;
    npc->pos_cart.y = npc_pos.y / 32;
    npc->traj_cart.x = npc->pos_cart.x;
    npc->traj_cart.y = npc->pos_cart.y;
    npc->tmp_move = -1;
    npc->is_fighter = 1;
    npc->stats = (stats_t) {NULL, 15, 2, 12, 1};
    npc->state = 1;
    npc->talks_index = 0;
    npc->talks =  malloc(sizeof(char **) * 2);
    npc->talks[0] = malloc(sizeof(char *) * 2);
    npc->talks[0][0] = my_strdup("What strenght ! Don't come near me !");
    npc->talks[0][1] = NULL;
    npc->talks[1] = NULL;
    npc->action_patern = NULL;
    npc->index_action = 0;
    npc->fighting.message_before =  malloc(sizeof(char *) * 2);
    npc->fighting.message_before[0] = my_strdup("What are you doing here ?! \nI'm gonna get you out of here !");
    npc->fighting.message_before[1] = NULL;
    npc->fighting.message_after = malloc(sizeof(char *) * 2);
    npc->fighting.message_after[0] = my_strdup("Oh ...\nmy head ...");
    npc->fighting.message_after[1] = NULL;
}

void initialize_npc(game_menu_t *game)
{
    game->texture_npc.villager_01 = make_texture("src/npc/npc_03.png");
    game->texture_npc.villager_02 = make_texture("src/npc/npc_02.png");
    game->texture_npc.villager_03 = make_texture("src/npc/npc_04.png");
    game->texture_npc.sbire = make_texture("src/npc/npc_01.png");
    game->texture_npc.boss = make_texture("src/npc/npc_05.png");
    game->npc = malloc(sizeof(npc_t) * NB_NPC);
    set_good_npc_01(&game->npc[0], &game->texture_npc);
    set_bad_npc_01(&game->npc[1], &game->texture_npc);
}