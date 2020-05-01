/*
** EPITECH PROJECT, 2020
** action_wait_npc.c
** File description:
** action to wait by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int action_wait_npc(npc_t *npc, player_t *player, float seconds)
{
    static char flag = 1;
    sfTime timer;

    if (flag == 1) {
        npc->move = sfClock_create();
        flag = 0;
    }
    timer = sfClock_getElapsedTime(npc->move);
    if (sfTime_asSeconds(timer) >= seconds) {
        flag = 1;
        sfClock_destroy(npc->move);
        return (END_NPC_ACT);
    }
    return (0);
}