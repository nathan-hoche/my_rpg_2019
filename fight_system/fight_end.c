/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight end
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int check_end(fight_scene_t *fight)
{
    if (fight->player.stats.hp <= 0)
        return (1);
    if (fight->enemy.stats.hp <= 0)
        return (1);
    return (0);
}