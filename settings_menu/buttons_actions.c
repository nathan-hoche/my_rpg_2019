/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** settings menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

int action_plus_fx(csfml_t *page)
{
    if (page->settings.fx_lvl != 100)
        page->settings.fx_lvl += 10;
    sfSound_setVolume(page->music.sound_but, page->settings.fx_lvl);
    sfSound_play(page->music.sound_but);
    return (0);
}

int action_minus_fx(csfml_t *page)
{
    if (page->settings.fx_lvl != 0)
        page->settings.fx_lvl -= 10;
    sfSound_setVolume(page->music.sound_but, page->settings.fx_lvl);
    sfSound_play(page->music.sound_but);
    return (0);
}

int action_plus_music(csfml_t *page)
{
    if (page->settings.music_lvl != 100)
        page->settings.music_lvl += 10;
    sfMusic_setVolume(page->music.menu, page->settings.music_lvl);
    sfSound_play(page->music.sound_but);
    return (0);
}

int action_minus_music(csfml_t *page)
{
    if (page->settings.music_lvl != 0)
        page->settings.music_lvl -= 10;
    sfMusic_setVolume(page->music.menu, page->settings.music_lvl);
    sfSound_play(page->music.sound_but);
    return (0);
}

int action_return(csfml_t *page)
{
    sfSound_play(page->music.sound_but);
    return (1);
}