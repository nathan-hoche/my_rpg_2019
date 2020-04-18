/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_skin
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void texture_male(csfml_t *page)
{
    sfSprite_setTexture(page->player.player, \
    page->player.texture_male, 0);
}

static void texture_female(csfml_t *page)
{
    sfSprite_setTexture(page->player.player, \
    page->player.texture_female, 0);
}

void event_skin(csfml_t *page)
{
    sfVector2f size_player = {64, 64};
    int pos[NB_TEXTURE_PLAYER][2] = {{0, 0}, {0, 0}};
    static void (*texture[NB_TEXTURE_PLAYER])() = {texture_male, \
    texture_female};

    for (int i = 0; i != NB_TEXTURE_PLAYER;i++)
        if (button_is_clicked((sfVector2f){pos[i][0], pos[i][1]}, \
        size_player, page->window) == 0)
            texture[i](page);
}