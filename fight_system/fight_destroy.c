/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight system destroy functions
*/

#include "struct.h"

void fight_destroy(fight_scene_t *fight)
{
    sfSprite_destroy(fight->back.sp_back);
    sfTexture_destroy(fight->back.tx_back);
    sfSprite_destroy(fight->player.sp);
    sfTexture_destroy(fight->attacks.txtr_shield);
    sfTexture_destroy(fight->attacks.txtr_sword);
    sfSprite_destroy(fight->enemy.sp);
    sfSprite_destroy(fight->fight_buttons.button_atk);
    sfTexture_destroy(fight->fight_buttons.texture);
    sfSprite_destroy(fight->fight_buttons.button_def);
    sfSprite_destroy(fight->attacks.sword_slash);
    sfSprite_destroy(fight->attacks.shield);
    if (sfSound_getStatus(fight->fx_sword_atk.sound))
        sfSound_stop(fight->fx_sword_atk.sound);
    sfSound_destroy(fight->fx_sword_atk.sound);
    sfSoundBuffer_destroy(fight->fx_sword_atk.buf);
}