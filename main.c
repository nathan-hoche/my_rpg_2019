/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "struct.h"
#include "scene.h"
#include "my_rpg.h"
#include "my.h"

static void main_initialization(csfml_t *page)
{
    initialize_window(page);
    page->button = make_texture("src/button.png");
    page->size_button.x = 285;
    page->size_button.y = 110;
    page->font_itim = sfFont_createFromFile("src/font_itim.ttf");
    page->act_scene = 1;
}

static void main_destroy(csfml_t *page)
{
    sfRenderWindow_close(page->window);
    sfFont_destroy(page->font_itim);
    sfTexture_destroy(page->button);
    sfRenderWindow_destroy(page->window);
}

static int game_loop(void)
{
    csfml_t page;

    main_initialization(&page);
    while (page.act_scene != ID_CLOSE) {
        for (int cursor = 0; cursor < NB_SCENE && \
        page.act_scene != ID_CLOSE; cursor++) {
            if (scene_tab[cursor].id_scene == page.act_scene)
                scene_tab[cursor].scene(&page);
        }
    }
    main_destroy(&page);
    return (0);
}

int main(int ac, char **av)
{
    game_loop();
    return (0);
}