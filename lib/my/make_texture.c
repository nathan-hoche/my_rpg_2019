/*
** EPITECH PROJECT, 2020
** -YukiLib_CSFML-
** File description:
** make_texture
*/
#include "my.h"

sfTexture *make_texture(char *link_texture)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(link_texture, NULL);
    return (texture);
}