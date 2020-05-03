/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop the game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int test(player_t *player, npc_t *npc, int dir, int dist)
{
    if (player->pos_cart.x == npc->pos_cart.x && 
    player->pos_cart.y >= npc->pos_cart.y - dist && player->pos_cart.y < npc->pos_cart.y)
        return (1);
    return (0);
/* 
    if (player->pos_cart.x <= npc->pos_cart.x && 
    player->pos_cart.y == npc->pos_cart.y - dist)
        return (1);

    if (player->pos_cart.x == npc->pos_cart.x && 
    player->pos_cart.y <= npc->pos_cart.y + dist)
        return (1); */
}

static void adventure_step(game_menu_t *game, csfml_t *general)
{
    char *test[] = {"LOL", "OMG", NULL};

    if (general->player.pos_traj.x == 46) {
        game->on_msg = -1;
        general->player.player_rect.top = 64;
        if (action_message(test, game, general) == 1) {
            general->player.pos_traj.x = general->player.pos_cart.x;
            game->on_msg = 0;
        }
    }
}

static void game_display(game_menu_t *game, csfml_t *general)
{
    sfRenderWindow_clear(general->window, sfBlack);
    sfRenderWindow_drawSprite(general->window, game->back_grass, NULL);
    display_map_core(game, general);
    player_core(general, game);
    display_player_with_entities(general, game);
    adventure_step(game, general);
    if (test(&general->player, &game->npc[0], 2, 3))
        puts("SEE");
    //printf("%d, %d\n", general->player.pos_cart.x, general->player.pos_cart.y);

    message_management(game, general);
    fight_management(game, general);
    sfRenderWindow_drawSprite(general->window, game->entity[0].sp, NULL);
    if (game->on_fight == 0)
        camera_view(game, general);
    display_inventory(general, game);
    sfRenderWindow_display(general->window);
}

void game_menu(csfml_t *general)
{
    game_menu_t game;

    initialize_game_core(&game, general);
    while (general->act_scene == ID_GAME) {
        while (sfRenderWindow_pollEvent(general->window, &general->event))
            game_event(general, &game);
        game_display(&game, general);
        if (game.inter == 1) {
            game.inter_lock = 1;
            game.inter = 0;
        }
    }
    free_game_ressources(&game);
}