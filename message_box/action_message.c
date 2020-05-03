/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int action_message(char **message, game_menu_t *game, csfml_t *general)
{
    static int index = 0;

    printf("%s  -->>  %d\n",message[index], index);
    if (message == NULL || message[index] == NULL) {
        index = 0;
        return (1);
    }
    sfText_setString(game->message_box.one, message[index]);
    index++;
    return (0);
}