/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage player movements
*/

#include "my_rpg.h"
#include "struct.h"

void player_key_orientation(sfEvent event, player_t *player, game_menu_t *game)
{
    int key[4] = {sfKeyS, sfKeyQ, sfKeyD, sfKeyZ};
    int way[4] = {0, 64, 128, 192};

    for (int i = 0; player->on_move == 0 && i != 4; i++) {
        if (player->on_move == 0 && sfKeyboard_isKeyPressed(key[i]) == 1) {
            if (player_collision_core(key[i], player, game) == 1)
                return;
            player->player_rect.top = way[i];
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

void camera_view(game_menu_t *game, csfml_t *general)
{
    sfVector2f player_pos;

    player_pos.x = general->player.pos_px.x;
    player_pos.y = general->player.pos_px.y;
    sfView_setCenter(general->views.actual_view, player_pos);
    sfRenderWindow_setView(general->window, general->views.actual_view);
}

void player_core(csfml_t *general, game_menu_t *game)
{
    player_key_orientation(general->event, &general->player, game);
    if (general->player.on_move != 0)
        player_movement(&general->player);
    if (general->player.on_anim != 0)
        player_animation(&general->player);
}