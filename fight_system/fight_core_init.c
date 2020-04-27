/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** initialize fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void fight_initialize(pause_menu_t *pause)
{
    pause->back.tx_back = make_texture(BACKGROUND_1);
    pause->back.sp_back = make_sprite(pause->back.tx_back);
}