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
    sfRenderWindow_drawSprite(window, game->back.s_back, NULL);
    sfRenderWindow_display(window);
}

static void game_initialize(game_menu_t *game)
{
    game->back.t_back = make_texture("src/test.png");
    game->back.s_back = make_sprite(game->back.t_back);
}

static void game_destroy(game_menu_t *game)
{
    sfSprite_destroy(game->back.s_back);
    sfTexture_destroy(game->back.t_back);
}

void game_menu(csfml_t *page)
{
    game_menu_t game;

    game_initialize(&game);
    while (page->act_scene == ID_GAME) {
        game_display(&game, page->window);
        if (sfRenderWindow_pollEvent(page->window, &page->event))
            game_event(page);
    }
    game_destroy(&game);
}