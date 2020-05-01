/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_skin
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void texture_male(player_t *player)
{
    sfSprite_setTexture(player->player, \
    player->texture_male, 0);
    player->gender = 1;
}

static void texture_female(player_t *player)
{
    sfSprite_setTexture(player->player, \
    player->texture_female, 0);
    player->gender = 0;
}

int event_skin(csfml_t *page)
{
    sfVector2f size_player = {64 * 4, 64 * 4};
    int pos[NB_TEXTURE_PLAYER][2] = {{1050, 300}, {600, 300}};
    static void (*texture[NB_TEXTURE_PLAYER])() = {texture_male, \
    texture_female};

    for (int i = 0; i != NB_TEXTURE_PLAYER;i++)
        if (button_is_hover((sfVector2f){pos[i][0], pos[i][1]}, \
        size_player, page->window) == 1) {
            texture[i](&page->player);
            page->act_scene = ID_GAME;
            return (0);
        }
    return (1);
}