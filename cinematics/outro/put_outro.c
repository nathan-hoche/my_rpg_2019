/*
** EPITECH PROJECT, 2020
** outro.c
** File description:
** outro
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

void display_outro(sfRenderWindow *window, outro_t *outro)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
    sfSleep((sfTime) {500000});
    sfRenderWindow_drawText(window, outro->ending_txt, NULL);
    sfRenderWindow_display(window);
    sfSleep((sfTime) {2000000});
    sfText_destroy(outro->ending_txt);
}