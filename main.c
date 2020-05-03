/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "struct.h"
#include "scene.h"
#include "my_rpg.h"
#include "my.h"

static void init_music(music_t *music)
{
    music->menu = sfMusic_createFromFile(MUSIC_MENU);
    music->beach = sfMusic_createFromFile(MUSIC_BEACH);
    music->sound_but = sfSound_create();
    music->sound_but_buf = sfSoundBuffer_createFromFile(CLICK_SOUND);
    sfSound_setBuffer(music->sound_but, music->sound_but_buf);
    sfSound_setVolume(music->sound_but, DEFAULT_FX_LEVEL);
    sfMusic_setLoop(music->menu, sfTrue);
    sfMusic_setLoop(music->beach, sfTrue);
    sfMusic_play(music->menu);
    sfMusic_play(music->beach);
    sfMusic_setVolume(music->menu, DEFAULT_MUSIC_LEVEL);
    sfSound_setVolume(music->sound_but, DEFAULT_FX_LEVEL);
    sfMusic_setVolume(music->beach, DEFAULT_MUSIC_LEVEL);
    game_music(music);
}

static void main_initialization(csfml_t *page)
{
    initialize_window(page);
    page->button_1 = make_texture(BUT_1_TXTR);
    page->button_2 = make_texture(BUT_2_TXTR);
    page->size_button.x = 285;
    page->size_button.y = 110;
    page->settings.fx_lvl = DEFAULT_FX_LEVEL;
    page->settings.music_lvl = DEFAULT_MUSIC_LEVEL;
    page->font_itim = sfFont_createFromFile(FONT_1);
    page->act_scene = 1;
    init_player(&page->player);
    init_music(&page->music);
}

static void main_destroy(csfml_t *page)
{
    sfMusic_destroy(page->music.menu);
    sfMusic_destroy(page->music.beach);
    sfMusic_destroy(page->music.fight);
    sfMusic_destroy(page->music.adven);
    sfSoundBuffer_destroy(page->music.sound_but_buf);
    sfSound_destroy(page->music.sound_but);
    sfRenderWindow_close(page->window);
    sfFont_destroy(page->font_itim);
    sfTexture_destroy(page->button_1);
    sfRenderWindow_destroy(page->window);
    destroy_player(&page->player);
}

static int main_loop(void)
{
    csfml_t page;

    main_initialization(&page);
    for (int cursor = 0; cursor <= NB_SCENE && \
    page.act_scene != ID_CLOSE; cursor++) {
        if (cursor == NB_SCENE)
            cursor == 0;
        if (scene_tab[cursor].id_scene == page.act_scene)
            scene_tab[cursor].scene(&page);
    }
    main_destroy(&page);
    return (0);
}

int main(int ac, char **av)
{
    main_loop();
    return (0);
}