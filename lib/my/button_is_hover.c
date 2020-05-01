/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button_is_clicked
*/
#include "my.h"

int button_is_hover(sfVector2f pos_sprite, \
sfVector2f sprite_size, sfRenderWindow *window)
{
    sfVector2i click;

    click = sfMouse_getPositionRenderWindow(window);
    if (click.x <= (pos_sprite.x + sprite_size.x) && \
    click.y <= (pos_sprite.y + sprite_size.y) && \
    click.x >= pos_sprite.x && click.y >= \
    pos_sprite.y)
        return (1);
    return (0);
}