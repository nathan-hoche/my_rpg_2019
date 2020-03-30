/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** main
*/

#include "include/my_rpg.h"
#include "include/my.h"

static void main_initialization(csfml *page)
{
    initialize_window(page);
    page->button = make_texture("src/button.png");
    page->size_button.x = 285;
    page->size_button.y = 110;
    page->font_itim = sfFont_createFromFile("src/font_itim.ttf");
}

static void main_destroy(csfml *page)
{
    sfFont_destroy(page->font_itim);
    sfTexture_destroy(page->button);
    sfRenderWindow_destroy(page->window);
}

static int game_loop(int ac)
{
    csfml page;
    static int (*menu[2])() = {start_menu, game_menu};

    main_initialization(&page);
    for (int x = 0; sfRenderWindow_isOpen(page.window) && x != -1;)
        x = menu[x](&page);
    main_destroy(&page);
    return (0);
}

int main(int ac, char **av)
{
    int x = game_loop(ac);
    return (x);
}