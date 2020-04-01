/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_movement
*/

#include "my_rpg.h"
#include "struct.h"

void clock_player_animation(player_t *player)
{
    sfInt64 time;

    time = sfClock_getElapsedTime \
    (player->animation).microseconds;
    if (time >= 50000) {
        player->player_rect.left += 64;
        if (player->player_rect.left >= 256)
            player->player_rect.left = 0;
        sfSprite_setTextureRect(player->player, player->player_rect);
        sfClock_restart(player->animation);
    }
}

void player_orientation(sfEvent event, player_t *player)
{
    int key[4] = {sfKeyS, sfKeyQ, sfKeyD, sfKeyZ};
    int way[4] = {0, 64, 128, 192};
    int direction[8][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

    for (int i = 0; i != 4;i++)
        if (event.key.code == key[i] && \
        event.type == sfEvtKeyPressed) {
            player->player_rect.top = way[i];
            //player->move_direction.x += direction[i][0];
            //player->move_direction.y += direction[i][1];
            //sfSprite_setPosition(player->player, player->move_direction);
        }
}