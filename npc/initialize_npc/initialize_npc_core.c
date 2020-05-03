/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void initialize_npc(game_menu_t *game)
{
    game->texture_npc.villager_01 = make_texture(NPC_01);
    game->texture_npc.villager_02 = make_texture(NPC_02);
    game->texture_npc.villager_03 = make_texture(NPC_03);
    game->texture_npc.sbire = make_texture(NPC_04);
    game->texture_npc.boss = make_texture(NPC_05);
    game->npc = NULL;
    game->npc = malloc(sizeof(npc_t) * NB_NPC);
    set_good_npc_01(&game->npc[0], &game->texture_npc);
    set_good_npc_02(&game->npc[1], &game->texture_npc);
    set_good_npc_03(&game->npc[2], &game->texture_npc);
    set_bad_npc_01(&game->npc[3], &game->texture_npc);
    set_bad_npc_02(&game->npc[4], &game->texture_npc);
}