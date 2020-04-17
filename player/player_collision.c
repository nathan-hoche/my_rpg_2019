/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collision
*/

#include "my_rpg.h"
#include "struct.h"

void player_check_collision(player_t *player, sfVector2f pos_block)
{
    sfVector2f pos;
    sfVector2f size;

    pos = player->move_direction;
    if ((pos_block.x -24) <= pos.x && pos.x <= (pos_block.x + 32) && \
    (pos_block.y -24) <= pos.y && pos.y <= (pos_block.y + 32))
        player->collision = 0;
}