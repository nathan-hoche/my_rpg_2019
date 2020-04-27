/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** make a lib
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>

sfSprite *make_sprite(sfTexture *texture);
sfTexture *make_texture(char *link_texture);
char *my_getstr(int nb);
int button_is_clicked(sfVector2f pos_sprite, \
sfVector2f sprite_size, sfRenderWindow *window);
sfText *make_text(sfFont* font, char *str, sfVector2f pos, int size);
char *my_revstr(char *str);
char *my_getnbr(int nb);
char *my_strcat(char *dest, char *src);

#endif /* !MY_H_ */
