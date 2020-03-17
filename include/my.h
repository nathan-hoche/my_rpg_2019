/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** make a lib
*/

#ifndef MY_H_
#define MY_H_
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct background {
    sfTexture* t_back;
    sfSprite* s_back;
}background;

typedef struct csfml {
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    background back;
}csfml;

void initialize_window(csfml *page);
sfSprite *make_sprite(sfTexture *texture);
sfTexture *make_texture(char *link_texture);
char *my_getstr(int nb);
int button_is_clicked(sfVector2f pos_sprite, \
sfVector2f sprite_size, sfRenderWindow *window);
sfText *make_text(sfFont* font, char *str, sfVector2f pos, int size);
char *my_revstr(char *str);

#endif /* !MY_H_ */

void main_initialize(csfml *page);
void main_display(csfml *page);
void main_destroy(csfml *page);