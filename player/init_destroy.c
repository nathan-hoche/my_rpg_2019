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
    player->texture_male = make_texture(PLAYER_TEXTURE_1);
    player->texture_female = make_texture(PLAYER_TEXTURE_2);
    player->player = make_sprite(player->texture_male);
    player->animation = sfClock_create();
    player->player_rect = (sfIntRect) \
        {0, 0, PLAYER_SP_SIZ_X, PLAYER_SP_SIZ_Y};
    sfSprite_setTextureRect(player->player, player->player_rect);
    sfSprite_setOrigin(player->player, (sfVector2f) {32, 48 + 6});
    player->stats.speed = 10;
    player->stats.hp = 20;
    player->stats.atk = 10;
    player->stats.armor = 10;
    player->dir_view = 0;
}

void init_game_player(player_t *player, game_scene_t *game_scene)
{
    player->movement = sfClock_create();
    player->animation = sfClock_create();
    player->pos_cart = (sfVector2i) {0, 0};
    player->pos_px = (sfVector2f) {0, 0};
    player->on_move = 0;
    player->on_anim = 0;
    player->pos_traj.x = player->pos_cart.x + 1;
    player->pos_traj.y = player->pos_cart.y;
    sfSprite_setPosition(player->player, game_scene->starting_pos);
}

void destroy_player(player_t *player)
{
    sfClock_destroy(player->animation);
    sfSprite_destroy(player->player);
    sfTexture_destroy(player->texture_male);
    sfTexture_destroy(player->texture_female);
}