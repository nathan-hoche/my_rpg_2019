/*
** EPITECH PROJECT, 2020
** outro.c
** File description:
** outro
*/

#include "my.h"
#include "my_rpg.h"
#include "struct.h"

void display_end_game(sfRenderWindow *window, outro_t *outro)
{
    sfText_setString(outro->ending_txt, "The End.");
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
    sfSleep((sfTime) {500000});
    sfSprite_setScale(outro->endgame_sp, (sfVector2f) {3.5, 3.5});
    sfRenderWindow_drawSprite(window, outro->endgame_sp, NULL);
    sfRenderWindow_display(window);
    sfSleep((sfTime) {2000000});
    sfTexture_destroy(outro->endgame_tx);
    sfSprite_destroy(outro->endgame_sp);
}

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