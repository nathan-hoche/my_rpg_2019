/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage player movements
*/

#include "my_rpg.h"
#include "struct.h"

void player_movement(player_t *player)
{
    static int distance = 0;
    int direction[4][2] = {{0, -4}, {4, 0}, {0, 4}, {-4, 0}};
    sfTime timer = sfClock_getElapsedTime(player->movement);

    if (timer.microseconds >= 25000) {
        sfSprite_move(player->player, (sfVector2f) \
            {direction[player->on_move - 1][0], \
            direction[player->on_move - 1][1]});
        distance += 4;
        sfClock_restart(player->movement);
    }
    if (distance == 32) {
        player->on_move = 0;
        distance = 0;
    }
}

void player_animation(player_t *player)
{
    sfTime time;

    time = sfClock_getElapsedTime(player->animation);
    if (time.microseconds >= 55000) {
        player->player_rect.left += 64;
        if (player->player_rect.left >= 256) {
            player->player_rect.left = 0;
            player->on_anim = 0;
        }
        sfSprite_setTextureRect(player->player, player->player_rect);
        sfClock_restart(player->animation);
    }
}