/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_player
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void init_player(player_t *player)
{
    player->texture_player = make_texture("src/perso.png");
    player->player = make_sprite(player->texture_player);
    player->animation = sfClock_create();
    player->player_rect = (sfIntRect) {0, 0, 64, 64};
    player->move_direction = (sfVector2f) {0, 0};
    sfSprite_setPosition(player->player, player->move_direction);
    sfSprite_setTextureRect(player->player, player->player_rect);
    player->nb_move = 0;
    player->move_ways = 0;
    player->collision = -1;
}

void destroy_player(player_t *player)
{
    sfClock_destroy(player->animation);
    sfSprite_destroy(player->player);
    sfTexture_destroy(player->texture_player);
}