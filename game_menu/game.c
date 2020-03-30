/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void game_event(csfml_t *page)
{
    if (page->event.type == sfEvtClosed)
        page->act_scene = ID_CLOSE;
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        pause_menu(page);
}

static void game_display(game_menu_t *game, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    map_display(&game->first_scene, game->tile, window);
    sfRenderWindow_display(window);
}

static void game_initialize(game_menu_t *game)
{
    game->first_scene.map_file = "map/map.txt";
    init_game_scene(&game->first_scene);
    game->texture_tile = make_texture("src/tile.png");
    game->tile = make_sprite(game->texture_tile);
}

static void game_destroy(game_menu_t *game)
{
}

void game_menu(csfml_t *page)
{
    game_menu_t game;

    game_initialize(&game);
    while (page->act_scene == ID_GAME) {
        game_display(&game, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            game_event(page);
    }
    game_destroy(&game);
}