/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight system destroy functions
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void fight_destroy(fight_scene_t *fight)
{
    sfSprite_destroy(fight->back.sp_back);
    sfTexture_destroy(fight->back.tx_back);
}