/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
**  play menu game
*/

#include "../include/my_rpg.h"
#include "../include/my.h"

static int game_event(csfml *page, int x)
{
    if (page->event.type == sfEvtClosed)
        return (-1);
    else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed)
        return (pause_menu(page));
    return (0);
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

int game_menu(csfml *page)
{
    game_menu_t game;
    int x = 0;

    game_initialize(&game);
    while (x == 0) {
        game_display(&game, page->window);
        while (sfRenderWindow_pollEvent(page->window, &page->event))
            x = game_event(page, x);
    }
    game_destroy(&game);
    return (x);
}