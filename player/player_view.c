/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage player movements
*/

#include "my_rpg.h"
#include "struct.h"

void camera_view(game_menu_t *game, csfml_t *general)
{
    sfVector2f player_pos;

    player_pos.x = general->player.pos_px.x;
    player_pos.y = general->player.pos_px.y;
    sfView_setCenter(general->views.actual_view, player_pos);
    sfRenderWindow_setView(general->window, general->views.actual_view);
}