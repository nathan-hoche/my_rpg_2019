/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop the game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void game_display(game_menu_t *game, csfml_t *general)
{
    sfRenderWindow_clear(general->window, sfBlack);
    sfRenderWindow_drawSprite(general->window, game->back_grass, NULL);
    display_map_core(game, general);
    player_core(general, game);
    display_player_with_entities(general, game);
    message_management(game, general);
    fight_management(game, general);
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