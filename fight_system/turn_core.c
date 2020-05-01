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
    sfRenderWindow_drawSprite(window, fight->button_atk.sp, NULL);
    sfRenderWindow_drawSprite(window, fight->button_def.sp, NULL);
    sfRenderWindow_drawText(window, fight->button_atk.txt, NULL);
    sfRenderWindow_drawText(window, fight->button_def.txt, NULL);
}

static void check_button_attack(fight_scene_t *fight, sfRenderWindow *window, \
sfBool clicked)
{
    sfTime test;

    test.microseconds = 100000;
    if (button_is_hover(fight->button_atk.pos, \
    fight->button_atk.size, window)) {
        if (clicked == sfTrue) {
            fight->atk_step = 1;
            fight_button_clicked(&fight->button_atk);
            display_buttons(fight, window);
            sfRenderWindow_display(window);
            sfSleep(test);
        } else {
            fight_button_hover(&fight->button_atk);
        }
    } else {
        fight_button_no_hover(&fight->button_atk);
    }
}

static void check_button_defence(fight_scene_t *fight, sfRenderWindow *window, \
sfBool clicked)
{
    sfTime test;

    test.microseconds = 100000;
    if (button_is_hover(fight->button_def.pos, \
    fight->button_atk.size, window)) {
        if (clicked == sfTrue) {
            fight->player.def = sfTrue;
            fight->turn_state = 1;
            fight_button_clicked(&fight->button_def);
            display_buttons(fight, window);
            sfRenderWindow_display(window);
            sfSleep(test);
        } else {
            fight_button_hover(&fight->button_def);
        }
    } else {
        fight_button_no_hover(&fight->button_def);
    }
}

static void buttons_management(fight_scene_t *fight, sfRenderWindow *window)
{
    sfBool clicked = sfFalse;

    clicked = sfMouse_isButtonPressed(sfMouseLeft);
    check_button_attack(fight, window, clicked);
    check_button_defence(fight, window, clicked);
    display_buttons(fight, window);
}

void turn_core(fight_scene_t *fight, sfRenderWindow *window)
{
    int ai_choice = 0;

    if (fight->turn_state == 0 && fight->atk_step == 0) {
        fight->player.def = sfFalse;
        buttons_management(fight, window);
    }
    if (fight->turn_state == 1)
        sfRenderWindow_drawText(window, fight->info_area.txt_wait, NULL);
    if (fight->turn_state == 1 && fight->atk_step == 0) {
        fight->enemy.def = sfFalse;
        ai_choice = (rand() + 1) % 2;
        if (ai_choice == 1) {
            fight->enemy.def = sfTrue;
            fight->turn_state = 0;
        } else {
            fight->atk_step = 1;
        }
    }
}