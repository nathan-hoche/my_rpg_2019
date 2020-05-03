/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game event
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void talk_management(csfml_t *general, game_menu_t *game, \
npc_t *npc, int id)
{
    if (npc->talks_index == 1 && npc->talk_01 != NULL) {
        action_npc_focus_player(&general->player, npc);
        game->on_msg = id + 1;
    }
}

static void check_interraction_with_npc(csfml_t *general, game_menu_t *game, \
npc_t *npc, int id)
{
    int testo = 0;

    if (general->player.pos_view.x == npc->pos_cart.x &&
    general->player.pos_view.y == npc->pos_cart.y)
        testo = 1;
    if (general->player.dir_view == 3 && \
    (general->player.pos_view.x == npc->pos_cart.x &&
    general->player.pos_view.y == npc->pos_cart.y - 1))
        testo = 1;
    if (testo == 1) {
        action_npc_focus_player(&general->player, npc);
        if (npc->is_fighter == 1)
            game->on_fight = id + 1;
        else
            talk_management(general, game, npc, id);
    }
}

static void manage_key_interraction(csfml_t *general, game_menu_t *game)
{
    if (game->inter_lock == 0)
        game->inter = 1;
    for (int i = 0; i < NB_NPC; i++)
        check_interraction_with_npc(general, game, &game->npc[i], i);
}

void game_event(csfml_t *general, game_menu_t *game)
{
    if (general->event.type == sfEvtClosed)
        general->act_scene = ID_CLOSE;
    else if (general->event.key.code == sfKeyEscape && \
    general->event.type == sfEvtKeyPressed) {
        sfSound_play(general->music.sound_but);
        pause_menu(general);
    }
    if (general->event.key.code == sfKeyE && \
    general->event.type == sfEvtKeyPressed)
        manage_key_interraction(general, game);
    else if (general->event.key.code == sfKeyE && \
    general->event.type == sfEvtKeyReleased) {
        game->inter = 0;
        game->inter_lock = 0;
    }
    manage_inventory_event(general, &game->inventory);
}