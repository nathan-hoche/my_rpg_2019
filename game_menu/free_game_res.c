/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free game ressources
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void free_npc(npc_t *npc)
{
    sfSprite_destroy(npc->sp);
}

void free_game_ressources(game_menu_t *game)
{
    destroy_entity(&game->small_flame, &game->big_flame);
    free_inventory(&game->inventory);
    free_stats(&game->inventory.stats);
    sfSprite_destroy(game->tile);
    sfSprite_destroy(game->back_grass);
    sfTexture_destroy(game->grass);
    sfTexture_destroy(game->texture_tile);
    sfTexture_destroy(game->texture_npc.villager_01);
    sfTexture_destroy(game->texture_npc.villager_02);
    sfTexture_destroy(game->texture_npc.villager_03);
    sfTexture_destroy(game->texture_npc.sbire);
    sfTexture_destroy(game->texture_npc.boss);
    for (int i = 0; i < NB_NPC; i++) {
        free_npc(&game->npc[i]);
    }
}