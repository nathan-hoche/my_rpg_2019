/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int display_message_box(game_menu_t *game, csfml_t *general)
{
    if (game->on_msg != 0) {
        sfText_setPosition(game->message_box.one, general->player.pos_px);
        sfSprite_setPosition(game->message_box.sp, general->player.pos_px);
        sfRenderWindow_drawSprite(general->window, game->message_box.sp, NULL);
        sfRenderWindow_drawText(general->window, game->message_box.one, NULL);
    }
}