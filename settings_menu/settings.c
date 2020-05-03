/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** settings menu
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int settings_event(csfml_t *page, settings_menu_t *set)
{
    int return_value = 0;

    if (page->event.type == sfEvtClosed) {
        page->act_scene = ID_CLOSE;
        return (0);
    } else if (page->event.key.code == sfKeyEscape && \
    page->event.type == sfEvtKeyPressed) {
        sfSound_play(page->music.sound_but);
        return (0);
    }
    for (int i = 0; page->event.type == sfEvtMouseButtonPressed && \
    i < NB_SET_MENU_B; i++) {
        if (button_obj_is_hover(&set->buttons[i], page->window) && \
        page->event.key.code == sfMouseLeft)
            return_value = set->buttons[i].action(page);
        if (return_value == 1)
            return (0);
    }
    return (1);
}

static void sounds_level_display(settings_menu_t *set, \
sfRenderWindow *window, csfml_t *page)
{
    char *str_lvl_music = my_getstr(page->settings.music_lvl);
    char *str_lvl_fx = my_getstr(page->settings.fx_lvl);

    sfRenderWindow_drawText(window, set->txt_music.text, NULL);
    sfRenderWindow_drawText(window, set->txt_fx.text, NULL);
    sfText_setString(set->txt_lvl_music.text, str_lvl_music);
    sfText_setString(set->txt_lvl_fx.text, str_lvl_fx);
    sfRenderWindow_drawText(window, set->txt_lvl_music.text, NULL);
    sfRenderWindow_drawText(window, set->txt_lvl_fx.text, NULL);
    free(str_lvl_music);
    free(str_lvl_fx);
}

static void settings_display(settings_menu_t *set, \
sfRenderWindow *window, csfml_t *page)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, set->back.sp_back, NULL);
    for (int i = 0; i < NB_SET_MENU_B; i++)
        sfRenderWindow_drawSprite(window, set->buttons[i].sprite, NULL);
    sounds_level_display(set, window, page);
    sfRenderWindow_display(window);
}

static void settings_destroy(settings_menu_t *set)
{
    sfSprite_destroy(set->back.sp_back);
    sfTexture_destroy(set->back.tx_back);
    for (int i = 0; i < NB_SET_MENU_B; i++)
        sfSprite_destroy(set->buttons[i].sprite);
}

void settings(csfml_t *page)
{
    settings_menu_t settings;
    int active = 1;

    settings_initialize(&settings, page);
    while (active != 0) {
        settings_display(&settings, page->window, page);
        while (sfRenderWindow_pollEvent(page->window, &page->event) \
        && active != 0)
            active = settings_event(page, &settings);
    }
    settings_destroy(&settings);
}