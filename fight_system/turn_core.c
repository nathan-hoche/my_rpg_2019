/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** turn core of the fight system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int buttons_management(fight_scene_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->fight_buttons.button_atk, NULL);
    sfRenderWindow_drawSprite(window, fight->fight_buttons.button_def, NULL);
    sfRenderWindow_drawText(window, fight->fight_buttons.txt_atk, NULL);
    sfRenderWindow_drawText(window, fight->fight_buttons.txt_def, NULL);
}

void turn_core(fight_scene_t *fight, sfRenderWindow *window)
{
    if (fight->turn_state == 0)
        buttons_management(fight, window);
    else
        sfRenderWindow_drawText(window, fight->info_area.txt_wait, NULL);
}