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
    int direction[4][2] = {{0, 4}, {-4, 0}, {4, 0}, {0, -4}};

    time = sfClock_getElapsedTime \
    (player->animation).microseconds;
    if (time >= 25000 && player->nb_move != 0 && \
    player->collision != player->move_ways) {
        player->player_rect.left += 64;
        if (player->player_rect.left >= 256 || player->nb_move == 1)
            player->player_rect.left = 0;
        player->move_direction.x += direction[player->move_ways][0];
        player->move_direction.y += direction[player->move_ways][1];
        sfSprite_setTextureRect(player->player, player->player_rect);
        sfSprite_setPosition(player->player, player->move_direction);
        player->nb_move--;
        player->collision = -1;
        sfClock_restart(player->animation);
    }
}

void player_orientation(sfEvent event, player_t *player)
{
    int key[4] = {sfKeyS, sfKeyQ, sfKeyD, sfKeyZ};
    int way[4] = {0, 64, 128, 192};

    for (int i = 0; i != 4; i++)
        if (event.key.code == key[i] && \
        event.type == sfEvtKeyPressed) {
            player->player_rect.top = way[i];
            player->move_ways = i;
            player->nb_move = 4;
        }
}