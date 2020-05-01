/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player core
*/

#include "my_rpg.h"
#include "struct.h"

static void update_player_pos(player_t *player, int i)
{
    switch (i) {
        case 0:
            player->pos_traj.x = player->pos_cart.x;
            player->pos_traj.y = player->pos_cart.y + 1;
            break;
        case 1:
            player->pos_traj.x = player->pos_cart.x - 1;
            player->pos_traj.y = player->pos_cart.y;
            break;
        case 2:
            player->pos_traj.x = player->pos_cart.x + 1;
            player->pos_traj.y = player->pos_cart.y;
            break;
        case 3:
            player->pos_traj.x = player->pos_cart.x;
            player->pos_traj.y = player->pos_cart.y - 1;
            break;
        default:
            break;
    }
}

static int player_key_orientation(player_t *player, game_menu_t *game, char i)
{
    int looking[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    int key[4] = {sfKeyS, sfKeyQ, sfKeyD, sfKeyZ};
    int way[4] = {0, 64, 128, 192};

    if (player->on_move == 0 && sfKeyboard_isKeyPressed(key[i]) == 1) {
        player->player_rect.top = way[i];
        player->pos_view = (sfVector2i) {player->pos_cart.x + \
        looking[i][0], player->pos_cart.y + looking[i][1]};
        if (player_collision_core(key[i], player, game) == 1) {
            sfSprite_setTextureRect(player->player, player->player_rect);
            return (1);
        }
        update_player_pos(player, i);
        player->on_move = i + 1;
        player->on_anim = 1;
    }
    return (0);
}

void player_key_analysis(sfEvent event, player_t *player, game_menu_t *game)
{
    for (char i = 0; player->on_move == 0 && i != 4; i++) {
        if (player_key_orientation(player, game, i))
            return;
    }
}

void player_core(csfml_t *general, game_menu_t *game)
{
    player_key_analysis(general->event, &general->player, game);
    if (general->player.on_move != 0)
        player_movement(&general->player);
    if (general->player.on_anim != 0)
        player_animation(&general->player);
}