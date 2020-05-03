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

    npc->pos_px = (sfVector2f) {(20 * 32) + 16, (19 * 32) + 10};
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
    npc->action_patern = NULL;
    npc->action_patern = &patern_npc_01;
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 = malloc(sizeof(char *) * 2);
    npc->talk_01[0] = my_strdup("Brigands have ravaged everything ! \nMy crops are ruined !");
    npc->talk_01[1] = NULL;
}

static void set_good_npc_02(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(34 * 32) + 16, (21 * 32) + 10};
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
    npc->action_patern = NULL;
    npc->action_patern = &patern_npc_02;
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 =  malloc(sizeof(char *) * 3);
    npc->talk_01[0] = my_strdup("They killed my goats while I looked on ! \n ... I have nothing left to lose ...");
    npc->talk_01[1] = my_strdup("... and don t go east into the forest, \n the brigants are still there");
    npc->talk_01[2] = NULL;
}

static void set_good_npc_03(npc_t *npc, npc_texture_t *npc_txtr)
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
    npc->is_fighter = 0;
    npc->tmp_move = -1;
    npc->index_action = 0;
    npc->state = 1;
    npc->action_patern = NULL;
    npc->action_patern = NULL;
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 =  malloc(sizeof(char *) * 3);
    npc->talk_01[0] = my_strdup("They killed my goats while I looked on ! \n ... I have nothing left to lose ...");
    npc->talk_01[1] = my_strdup("... and don t go east into the forest, \n the brigants are still there ");
    npc->talk_01[2] = NULL;
}

static void set_bad_npc_01(npc_t *npc, npc_texture_t *npc_txtr)
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
    npc->tmp_move = -1;
    npc->is_fighter = 1;
    npc->stats = (stats_t) {NULL, 15, 2, 12, 1};
    npc->state = 1;
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 = malloc(sizeof(char *) * 2);
    npc->talk_01[0] = my_strdup("What strenght ! Don't come near me !");
    npc->talk_01[1] = NULL;
    npc->action_patern = &patern_npc_04;
    npc->index_action = 0;
    npc->fighting.message_before = NULL;
    npc->fighting.message_before =  malloc(sizeof(char *) * 2);
    npc->fighting.message_before[0] = my_strdup("What are you doing here ?! \nI'm gonna get you out of here !");
    npc->fighting.message_before[1] = NULL;
    npc->fighting.message_after = NULL;
    npc->fighting.message_after = malloc(sizeof(char *) * 2);
    npc->fighting.message_after[0] = my_strdup("Oh ...\nmy head ...");
    npc->fighting.message_after[1] = NULL;
}

static void set_bad_npc_02(npc_t *npc, npc_texture_t *npc_txtr)
{
    sfVector2f npc_pos;

    npc->pos_px = (sfVector2f) {(54 * 32) + 16, (19 * 32) + 10};
    npc->tx_rect = (sfIntRect) {0, 128, 64, 64};
    npc->sp = make_sprite(npc_txtr->boss);
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
    npc->talks_index = 1;
    npc->talk_01 = NULL;
    npc->talk_01 = malloc(sizeof(char *) * 2);
    npc->talk_01[0] = my_strdup("What strenght ! Don't come near me !");
    npc->talk_01[1] = NULL;
    npc->action_patern = &patern_npc_05;
    npc->index_action = 0;
    npc->fighting.message_before = NULL;
    npc->fighting.message_before =  malloc(sizeof(char *) * 2);
    npc->fighting.message_before[0] = my_strdup("What are you doing here ?! \nI'm gonna get you out of here !");
    npc->fighting.message_before[1] = NULL;
    npc->fighting.message_after = NULL;
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
    game->npc = NULL;
    game->npc = malloc(sizeof(npc_t) * NB_NPC);
    set_good_npc_01(&game->npc[0], &game->texture_npc);
    set_good_npc_02(&game->npc[1], &game->texture_npc);
    set_good_npc_03(&game->npc[2], &game->texture_npc);
    set_bad_npc_01(&game->npc[3], &game->texture_npc);
    set_bad_npc_02(&game->npc[4], &game->texture_npc);
}