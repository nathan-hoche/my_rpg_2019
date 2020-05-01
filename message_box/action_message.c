/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int count_message(char **message)
{
    int count = 0;

    for (count = 0; message[count] != NULL; count++);
    return (count);
}

int action_message(char **message, game_menu_t *game)
{
    static int index = 0;

    if (message[index] == NULL) {
        index = 0;
        return (1);
    }
    sfText_setString(game->message_box.one, message[index]);
    index++;
    if (message[index] != NULL) {
        sfText_setString(game->message_box.two, message[index]);
        index++;
    } else {
        sfText_setString(game->message_box.two, " ");
        index = 0;
        return (1);
    }
    return (0);
}