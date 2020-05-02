/*
** EPITECH PROJECT, 2020
** action_move_npc.c
** File description:
** action of moving by npc
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int init_message_box(game_menu_t *game, csfml_t *general)
{
    sfVector2f pos = {0, 0};
    sfVector2f origin_box = {285, - 100};
    sfVector2f origin_one = {260, - 110};

    game->on_msg = 0;
    game->message_box.txtr = \
        sfTexture_createFromFile("src/message_box/box.png", NULL);
    game->message_box.sp = make_sprite(game->message_box.txtr);
    sfSprite_setOrigin(game->message_box.sp, origin_box);
    game->message_box.one = make_text(general->font_itim, " ", pos, 28);
    sfText_setColor(game->message_box.one, sfBlack);
    sfText_setOrigin(game->message_box.one, origin_one);
    return (0);
}