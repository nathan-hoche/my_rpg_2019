/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int manage_action_message(char **message, game_menu_t *game)
{
    int state = 0;

    state = action_message(message, game);
    game->on_msg = 2;
    if (state == 1) {
        game->on_msg = 0;
        return (1);
    }
    return (0);
}