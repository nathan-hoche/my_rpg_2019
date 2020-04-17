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
    player_orientation(page->event, &page->player);
}

static void game_display(game_menu_t *game, sfRenderWindow *window, \
player_t *player)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, game->back_grass, NULL);
    map_display(&game->first_scene, game->tile, player, window);
    clock_player_animation(player);
    sfRenderWindow_drawSprite(window, player->player, NULL);
    sfRenderWindow_display(window);
}

static void game_initialize(game_menu_t *game)
{
    game->first_scene.map_file = "map/map.txt";
    init_game_scene(&game->first_scene);
    game->texture_tile = make_texture("src/tile.png");
    game->tile = make_sprite(game->texture_tile);
    game->grass = make_texture("src/grass.png");
    game->back_grass = make_sprite(game->grass);
}

static void game_destroy(game_menu_t *game)
{
    sfTexture_destroy(game->grass);
    sfTexture_destroy(game->texture_tile);
    sfSprite_destroy(game->tile);
    sfSprite_destroy(game->back_grass);
}

void game_menu(csfml_t *page)
{
    game_menu_t game;

    game_initialize(&game);
    while (page->act_scene == ID_GAME) {
        game_display(&game, page->window, &page->player);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            game_event(page);
    }
    game_destroy(&game);
}