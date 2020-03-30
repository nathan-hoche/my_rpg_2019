/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check if button obj is over
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int button_obj_is_hover(button_t *button, sfRenderWindow *window)
{
    sfVector2i click;

    click = sfMouse_getPositionRenderWindow(window);
    if (click.x <= (button->sp_pos.x + button->sp_rect.width ) && \
        click.y <= (button->sp_pos.y + button->sp_rect.height) && \
        click.x >= button->sp_pos.x && click.y >= button->sp_pos.y)
        return (1);
    return (0);
}