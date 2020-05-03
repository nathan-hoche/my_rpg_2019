/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage attack animation
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void slash_animation(fight_scene_t *fight, csfml_t *general)
{
    sfTime timer;
    static char sound = 0;

    timer = sfClock_getElapsedTime(fight->clock_atk);
    if (timer.microseconds >= 5000) {
        fight->attacks.sword_slash_rect.left += 192;
        sfSprite_setTextureRect(fight->attacks.sword_slash, \
        fight->attacks.sword_slash_rect);
        if (sound == 0) {
            sfSound_play(fight->fx_sword_atk.sound);
            sound = 1;
        }
        if (fight->attacks.sword_slash_rect.left == 960) {
            fight->attacks.sword_slash_rect.left = 0;
            fight->atk_step = 3;
            sfClock_destroy(fight->clock_atk);
            sound = 0;
        }
    }
}

static void damage_stats(fighter_t *striker, fighter_t *target, \
fight_scene_t *fight)
{
    if (target->def == sfTrue) {
        target->stats.hp -= (int) striker->stats.atk * 0.3;
    } else {
        target->stats.hp -= (int) striker->stats.atk;
    }
    fight->atk_step = 4;
}

static void initialize_slash_pos(fighter_t *target, \
fight_scene_t *fight)
{
    sfVector2f pos_target;

    fight->clock_atk = sfClock_create();
    fight->atk_step = 2;
    pos_target = sfSprite_getPosition(target->sp);
    pos_target.x -= 150;
    pos_target.y -= 250;
    sfSprite_setPosition(fight->attacks.sword_slash, pos_target);
}

static void waiting_time(fighter_t *target, fight_scene_t *fight)
{
    static char init = 0;
    sfTime timer;

    if (init == 0) {
        init = 1;
        fight->clock_atk = sfClock_create();
    }
    timer = sfClock_getElapsedTime(fight->clock_atk);
    if (timer.microseconds >= 300000) {
        init = 0;
        sfClock_destroy(fight->clock_atk);
        if (fight->turn_state == 0)
            fight->turn_state = 1;
        else
            fight->turn_state = 0;
        fight->updater = 1;
        fight->atk_step = 0;
    }
}

void fight_attack_animation(fighter_t *striker, fighter_t *target, \
fight_scene_t *fight, csfml_t *general)
{
    static void (*function[4])() = {initialize_slash_pos, \
    slash_animation, damage_stats, waiting_time};

    if (fight->atk_step == 3)
        function[2](striker, target, fight);
    else if (fight->atk_step == 2) {
        function[1](fight, general);
        sfRenderWindow_drawSprite(general->window, \
        fight->attacks.sword_slash, NULL);
    } else
        function[fight->atk_step - 1](target, fight);
}