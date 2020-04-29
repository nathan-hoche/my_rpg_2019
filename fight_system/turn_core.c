/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** turn core of the fight system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void display_buttons(fight_scene_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->fight_buttons.button_atk, NULL);
    sfRenderWindow_drawSprite(window, fight->fight_buttons.button_def, NULL);
    sfRenderWindow_drawText(window, fight->fight_buttons.txt_atk, NULL);
    sfRenderWindow_drawText(window, fight->fight_buttons.txt_def, NULL);
}

static void buttons_management(fight_scene_t *fight, sfRenderWindow *window)
{
    sfBool clicked = sfFalse;

    display_buttons(fight, window);
    clicked = sfMouse_isButtonPressed(sfMouseLeft);
    if (button_is_hover(fight->fight_buttons.pos_butt_atk, \
    fight->fight_buttons.size_butt_atk, window)) {
        if (clicked == sfTrue)
            fight->atk_step = 1;
        else
            puts("HOVER\n");
    }
    if (button_is_hover(fight->fight_buttons.pos_butt_def, \
    fight->fight_buttons.size_butt_def, window)) {
        if (clicked == sfTrue) {
            fight->player.def = sfTrue;
            fight->turn_state = 1;
        }
        else
            puts("HOVER\n");
    }
}

void turn_core(fight_scene_t *fight, sfRenderWindow *window)
{
    if (fight->turn_state == 0 && fight->atk_step == 0) {
        fight->player.def = sfFalse;
        buttons_management(fight, window);
    }
    if (fight->turn_state == 1 && fight->atk_step == 0) {
        sfRenderWindow_drawText(window, fight->info_area.txt_wait, NULL);
        fight->atk_step = 1;
    }

}