/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage attack animation
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void slash_animation(fight_scene_t *fight)
{
    sfTime timer;

    timer = sfClock_getElapsedTime(fight->clock_atk);
    if (timer.microseconds >= 5000) {
        fight->sword_slash_rect.left += 192;
        sfSprite_setTextureRect(fight->sword_slash, fight->sword_slash_rect);
        if (fight->sword_slash_rect.left == 960) {
            fight->sword_slash_rect.left = 0;
            fight->atk_step = 3;
            sfClock_destroy(fight->clock_atk);
        }
    }
}

static void damage_stats(fighter_t *striker, fighter_t *target, 
fight_scene_t *fight)
{
    if (target->def == sfTrue) {
        target->stats.hp -= (int) striker->stats.atk * 0.3;
    } else {
        target->stats.hp -= (int) striker->stats.atk;
    }
    if (fight->turn_state == 0)
        fight->turn_state = 1;
    else
        fight->turn_state = 0;
    fight->updater = 1;
    fight->atk_step = 0;

}

void fight_attack_animation(fighter_t *striker, fighter_t *target, 
fight_scene_t *fight, sfRenderWindow *window)
{
    sfVector2f pos_target;

    if (fight->atk_step == 1) {
        fight->clock_atk = sfClock_create();
        fight->atk_step = 2;
        pos_target = sfSprite_getPosition(target->sp);
        pos_target.x -= 90;
        pos_target.y -= 110;
        sfSprite_setPosition(fight->sword_slash, pos_target);
    }
    sfRenderWindow_drawSprite(window, fight->sword_slash, NULL);
    if (fight->atk_step == 2)
        slash_animation(fight);
    if (fight->atk_step == 3)
        damage_stats(striker, target, fight);
}