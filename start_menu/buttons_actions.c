/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttons actions
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int action_start_button(csfml_t *page)
{
    sfSound_play(page->music.sound_but);
    skin(page);
    return (0);
}

int action_quit_button(csfml_t *page)
{
    sfSound_play(page->music.sound_but);
    page->act_scene = ID_CLOSE;
    return (0);
}

int action_settings_button(csfml_t *page)
{
    sfSound_play(page->music.sound_but);
    settings(page);
    return (0);
}

int action_howtoplay_button(csfml_t *page)
{
    sfSound_play(page->music.sound_but);
    how_to_play(page);
    return (0);
}