/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start fighting system
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int fight_controller(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    fight_core(general, game, npc);
    sfMusic_stop(general->music.fight);
    return (1);
}

int before_fight(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    if (npc->fighting.message_before == NULL) {
        game->on_msg = 0;
        sfMusic_play(general->music.fight);
        return (1);
    }
    else if (game->inter == 1 && \
    action_message(npc->fighting.message_before, game, general) == 1) {
        game->on_msg = 0;
        sfMusic_play(general->music.fight);
        return (1);
    }
    return (0);
}

int after_fight(game_menu_t *game, csfml_t *general, npc_t *npc)
{
    static char first = 1;

    game->on_msg = -1;
    if (npc->fighting.message_after == NULL)
        return (1);
    else if ((first == 1 || game->inter == 1 ) && \
    action_message(npc->fighting.message_after, game, general) == 1) {
        first = 1;
        return (1);
    }
    first = 0;
    return (0);
}

int manage_before_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step)
{
    if (step == 0 && before_fight(game, general, npc) == 1)
        step = 1;
    if (step == 1 && camera_fight_zoom(game, general) == 1)
        step = 2;
    return (step);
}

int manage_after_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step)
{
    if (step == 3 && after_fight(game, general, npc) == 1) {
        game->on_fight = 0;
        game->on_msg = 0;
        step = -1;
        npc->is_fighter = 0;
        return (step);
    }
    return (step);
}