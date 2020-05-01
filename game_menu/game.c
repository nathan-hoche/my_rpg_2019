/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop the game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void game_event(csfml_t *general, game_menu_t *game)
{
    if (general->event.type == sfEvtClosed)
        general->act_scene = ID_CLOSE;
    if (general->event.key.code == sfKeyEscape && \
    general->event.type == sfEvtKeyPressed) {
        sfSound_play(general->music.sound_but);
        pause_menu(general);
    }
    manage_inventory_event(general, &game->inventory);
}

static void player_gps(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->player);

    player->pos_cart.x = pos.x / 32;
    player->pos_cart.y = pos.y / 32;
    player->pos_px.x = pos.x;
    player->pos_px.y = pos.y;
}

static void game_display(game_menu_t *game, csfml_t *general)
{
    sfRenderWindow_clear(general->window, sfBlack);
    sfRenderWindow_drawSprite(general->window, game->back_grass, NULL);
    display_map_core(game, general);
    player_core(general, game);
    player_gps(&general->player);
    sfRenderWindow_drawSprite(general->window, general->player.player, NULL);
    if (game->on_fight == 0)
        camera_view(game, general);
    display_inventory(general, game);
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