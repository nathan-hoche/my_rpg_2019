/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void game_event(csfml_t *page, game_menu_t *game, inventory_t *inventory)
{
    if (page->event.type == sfEvtClosed)
        page->act_scene = ID_CLOSE;
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        pause_menu(page);
    else if (page->event.key.code == sfKeyE && \
    page->event.type == sfEvtKeyPressed)
        game->on_fight_zoom = 1;
    manage_inventory_event(page, inventory);
    player_orientation(page->event, &page->player);
}

static void camera_view(game_menu_t *game, csfml_t *page)
{
    sfVector2f player_pos = sfSprite_getPosition(page->player.player);

    sfView_setCenter(page->views.actual_view, player_pos);
    sfRenderWindow_setView(page->window, page->views.actual_view);
}

static void game_display(game_menu_t *game, csfml_t *page, \
inventory_t *inventory)
{
    sfRenderWindow_clear(page->window, sfBlack);
    sfRenderWindow_drawSprite(page->window, game->back_grass, NULL);
    clock_player_animation(&page->player);
    map_display(game->first_scene.map_layer01, &game->first_scene, \
        game->tile, page);
    map_display(game->first_scene.map_layer02, &game->first_scene, \
        game->tile, page);
    sfRenderWindow_drawSprite(page->window, page->player.player, NULL);
    if (game->on_fight_zoom == 0)
        camera_view(game, page);
    else
        camera_fight_zoom(game, page);
    if (inventory->status == 1) {
        sfRenderWindow_drawSprite(page->window, inventory->sp_bar, NULL);
        display_items(page->window, &inventory->items);
    }
    sfRenderWindow_display(page->window);
}

static void game_initialize(game_menu_t *game, csfml_t *page)
{
    game->first_scene.map_layer01_file = MAP_L01_FILE;
    game->first_scene.map_layer02_file = MAP_L02_FILE;
    init_game_scene(&game->first_scene);
    game->texture_tile = make_texture(MAP_SP_SHEET);
    game->tile = make_sprite(game->texture_tile);
    game->grass = make_texture(MAP_GROUND_1);
    game->back_grass = make_sprite(game->grass);
    page->views.default_view = sfRenderWindow_getDefaultView(page->window);
    page->views.actual_view = sfView_copy(page->views.default_view);
    sfView_zoom(page->views.actual_view, CAM_DEFAULT_ZOOM);
    page->views.default_player_view = sfView_copy(page->views.actual_view);
    sfRenderWindow_setView(page->window, page->views.actual_view);
    game->on_fight_zoom = 0;
}

void game_menu(csfml_t *page)
{
    game_menu_t game;
    inventory_t inventory;

    initialize_inventory(&inventory);
    game_initialize(&game, page);
    while (page->act_scene == ID_GAME) {
        game_display(&game, page, &inventory);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            game_event(page, &game, &inventory);
    }
    free_game_ressources(&game);
}