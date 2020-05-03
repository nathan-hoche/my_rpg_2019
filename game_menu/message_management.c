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
    if (npc->talks_index == 1) {
        if (action_message(npc->talk_01, game, general) == 1)
            game->on_msg = 0;
    }
    if (npc->talks_index == 2) {
        if (action_message(npc->talk_02, game, general) == 1)
            game->on_msg = 0;
    }
    return (0);
}



static int event_message(game_menu_t *game, csfml_t *general)
{
    static char flag = 0;
    int check = 0;

    if (game->on_msg == -2) {
        general->player.player_rect.top = 64;
        sfSprite_setTextureRect(general->player.player, general->player.player_rect);
        if (flag == 0) {
            check = action_message(game->step_one_txt, game, general);
            flag = 1;
        } else if (check == 0 && (game->inter == 1 || flag == 1) && \
        action_message(game->step_one_txt, game, general) == 1) {
            game->on_msg = 0;
            flag = 0;
            return (1);
        }
    }
    flag = 2;
    return (0);
}

int message_management(game_menu_t *game, csfml_t *general)
{
    if (game->inter == 1 && game->on_fight == 0 && game->on_msg >= -1 \
    && game->on_msg != 0)
        start_message(game, general, &game->npc[game->on_msg - 1]);
    else if (game->on_msg <= -2 && game->on_fight == 0)
        event_message(game, general);
    display_message_box(game, general);
    return (0);
}