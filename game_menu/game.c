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

    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(general->window, game->npc[i].sp, NULL);
        if (game->on_msg == 0)
            manage_npc_actions(&game->npc[i], &general->player);
    }
    sfRenderWindow_drawSprite(general->window, general->player.player, NULL);
    display_inventory(general, game);
    if (game->on_fight == 0)
        camera_view(game, general);
    manage_message_box(game, general);
    sfRenderWindow_display(general->window);
}

static void game_initialize(game_menu_t *game, csfml_t *general)
{
    game->game_scene.map_layer01_file = MAP_L01_FILE;
    game->game_scene.map_layer02_file = MAP_L02_FILE;
    init_game_scene(&game->game_scene);
    init_game_player(&general->player, &game->game_scene);
    game->texture_tile = make_texture(MAP_SP_SHEET);
    game->tile = make_sprite(game->texture_tile);
    game->grass = make_texture(MAP_GROUND_1);
    game->back_grass = make_sprite(game->grass);
    general->views.default_view = \
        sfRenderWindow_getDefaultView(general->window);
    general->views.actual_view = sfView_copy(general->views.default_view);
    sfView_zoom(general->views.actual_view, CAM_DEFAULT_ZOOM);
    general->views.default_player_view = \
        sfView_copy(general->views.actual_view);
    sfRenderWindow_setView(general->window, general->views.actual_view);
    initialize_inventory(&game->inventory);
    set_npc(game);
    init_message_box(game, general);
    game->on_fight = 0;
}

void game_menu(csfml_t *general)
{
    game_menu_t game;

    game_initialize(&game, general);
    while (general->act_scene == ID_GAME) {
        while (sfRenderWindow_pollEvent(general->window, &general->event))
            game_event(general, &game);
        game_display(&game, general);
    }
    free_game_ressources(&game);
}