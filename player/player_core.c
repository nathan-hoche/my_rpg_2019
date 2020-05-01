/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage player movements
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

void player_key_orientation(sfEvent event, player_t *player, game_menu_t *game)
{
    int key[4] = {sfKeyS, sfKeyQ, sfKeyD, sfKeyZ};
    int looking[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    int way[4] = {0, 64, 128, 192};

    for (int i = 0; player->on_move == 0 && i != 4; i++) {
        if (player->on_move == 0 && sfKeyboard_isKeyPressed(key[i]) == 1) {
            player->player_rect.top = way[i];
            player->pos_view = (sfVector2i) {player->pos_cart.x + \
            looking[i][0], player->pos_cart.y + looking[i][1]};
            //printf("POS : %d %d -> VIEW : %d %d\n", player->pos_cart.x, player->pos_cart.y, player->pos_view.x, player->pos_view.y);
            if (player_collision_core(key[i], player, game) == 1) {
                sfSprite_setTextureRect(player->player, player->player_rect);
                return;
            }
            update_player_pos(player, i);
            player->on_move = i + 1;
            player->on_anim = 1;
        }
    }
}

static void player_movement(player_t *player)
{
    static sfVector2f base = {0, 0};
    static int distance = 0;
    int direction[4][2] = {{0, 4}, {-4, 0}, {4, 0}, {0, -4}};
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

static void player_animation(player_t *player)
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

void player_core(csfml_t *general, game_menu_t *game)
{
    printf("PLAYER - pos(%d, %d) view(%d, %d) traj(%d, %d)\n", general->player.pos_cart.x, general->player.pos_cart.y, general->player.pos_view.x, general->player.pos_view.y, general->player.pos_traj.x, general->player.pos_traj.y);
    printf("NPC - pos(%d, %d) traj(%d, %d)\n\n", game->npc.pos_cart.x, game->npc.pos_cart.y, game->npc.traj_cart.x, game->npc.traj_cart.y);
    player_key_orientation(general->event, &general->player, game);
    if (general->player.on_move != 0)
        player_movement(&general->player);
    if (general->player.on_anim != 0)
        player_animation(&general->player);
}