/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game event
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void check_ineterraction(csfml_t *general, game_menu_t *game, npc_t *npc)
{
    char *test[] = {"On m'appel l'OVNI, ...", "Tulutututu", "J'adore les chips'", "subvention de l'etat", "Bonjour", "lolilol", NULL};
    int testo = 0;

    if (general->player.pos_view.x == npc->pos_cart.x &&
    general->player.pos_view.y == npc->pos_cart.y) {
        testo = 1;
    }
    if (general->player.dir_view == 3 && (general->player.pos_view.x == npc->pos_cart.x &&
    general->player.pos_view.y == npc->pos_cart.y - 1)) {
        testo = 1;
    }
    if (testo == 1) {
        if (npc->inter_talk_1 != NULL) {
            npc->inter_talk_1(test, game);
        }
    }
}

void game_event(csfml_t *general, game_menu_t *game)
{
    if (general->event.type == sfEvtClosed)
        general->act_scene = ID_CLOSE;
    if (general->event.key.code == sfKeyEscape && \
    general->event.type == sfEvtKeyPressed)
        pause_menu(general);
    else if (general->event.key.code == sfKeyE && \
    general->event.type == sfEvtKeyPressed) {
        for (int i = 0; i < 2; i++)
            check_ineterraction(general, game, &game->npc[i]);
    }
    manage_inventory_event(general, &game->inventory);
}