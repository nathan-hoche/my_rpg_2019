/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** make_sprite
*/
#include "../../include/my.h"

sfSprite *make_sprite(sfTexture *texture)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}