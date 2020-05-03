/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int start_message(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    if (action_message(game->npc[1].talk_1, game, general) == 1)
        game->on_msg = 0;
    return (0);
}

static int event_message(game_menu_t *game, csfml_t *general)
{
    static char flag = 0;
    int check = 0;
    char **step_one = NULL;
    

    if (game->on_msg == -2) {
        step_one = malloc(sizeof(char *) * 2);
        step_one[0] = my_strdup("Je devrais peut etre voir ce qu il \n se passe dans le village avant \n de continuer.");
        step_one[1] = NULL;
        if (flag == 0) {
            check = action_message(step_one, game, general);
            flag = 1;
        } else if (check == 0 && (game->inter == 1 || flag == 1) && \
        action_message(step_one, game, general) == 1) {
            game->on_msg = 0;
            free(step_one[0]);
            free(step_one[1]);
            free(step_one);
            flag = 0;
            return (1);
        }
        free(step_one[0]);
        free(step_one[1]);
        free(step_one);
    }
    flag = 2;
    return (0);
}

int message_management(game_menu_t *game, csfml_t *general)
{
    if (game->inter == 1 && game->on_fight == 0 && game->on_msg >= -1 \
    && game->on_msg != 0) {
        start_message(game, general, &game->npc[game->on_msg - 1]);
    }
    else if (game->on_msg <= -2 && game->on_fight == 0) {
        event_message(game, general);
    }
    display_message_box(game, general);
    return (0);
}