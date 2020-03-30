/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** make_text
*/
#include "../../include/my.h"

sfText *make_text(sfFont* font, char *str, sfVector2f pos, int size)
{
    sfText* text;

    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text , str);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}