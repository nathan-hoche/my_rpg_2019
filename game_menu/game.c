/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void game_event(csfml_t *page, game_menu_t *game)
{
    if (page->event.type == sfEvtClosed)
        page->act_scene = ID_CLOSE;
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        pause_menu(page);
    else if (page->event.key.code == sfKeyE && \
    page->event.type == sfEvtKeyPressed)
        game->on_fight = 1;

    player_orientation(page->event, &page->player);
}

static void camera_view(game_menu_t *game, csfml_t *page)
{
    sfVector2f test = sfSprite_getPosition(page->player.player);

    sfView_setCenter(page->view, test);
    sfRenderWindow_setView(page->window, page->view);
}

static void game_display(game_menu_t *game, csfml_t *page)
{
    sfRenderWindow_clear(page->window, sfBlack);
    sfRenderWindow_drawSprite(page->window, game->back_grass, NULL);
    map_display(&game->first_scene, game->tile, &page->player, page->window);
    clock_player_animation(&page->player);
    sfRenderWindow_drawSprite(page->window, page->player.player, NULL);
    if (game->on_fight == 0)
        camera_view(game, page);
    else
        camera_fight_zoom(game, page);
    sfRenderWindow_display(page->window);
}

static void game_initialize(game_menu_t *game, csfml_t *page)
{
    game->first_scene.map_file = MAP_FILE_1;
    init_game_scene(&game->first_scene);
    game->texture_tile = make_texture(MAP_SP_SHEET);
    game->tile = make_sprite(game->texture_tile);
    game->grass = make_texture(MAP_GROUND_1);
    game->back_grass = make_sprite(game->grass);
    page->view = sfRenderWindow_getView(page->window);
    sfView_zoom(page->view, 0.8);
    sfRenderWindow_setView(page->window, page->view);
    game->on_fight = 0;
}

void game_menu(csfml_t *page)
{
    game_menu_t game;

    game_initialize(&game, page);
    while (page->act_scene == ID_GAME) {
        game_display(&game, page);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            game_event(page, &game);
    }
    free_game_ressources(&game);
}