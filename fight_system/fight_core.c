/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static int fight_event(csfml_t *general)
{
    if (general->event.type == sfEvtClosed) {
        general->act_scene = ID_CLOSE;
        return (0);
    }
    else if (general->event.type == sfEvtKeyPressed && \
    general->event.key.code == sfKeyEscape)
        return (0);
    return (1);
}

static void fight_display(fight_scene_t *fight, sfRenderWindow *window, \
csfml_t *general)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, fight->back.sp_back, NULL);
    display_infos_areas(fight, window);
    turn_core(fight, window);
    sfRenderWindow_drawSprite(general->window, fight->player_sp, NULL);
    sfRenderWindow_drawSprite(general->window, fight->enemy_sp, NULL);
    sfRenderWindow_display(window);
}

void fight_core(csfml_t *general, game_menu_t *game)
{
    fight_scene_t fight;
    int active = 1;

    sfRenderWindow_setView(general->window, general->views.default_view);
    fight_initialize(&fight, general);
    while (active != 0) {
        fight_display(&fight, general->window, general);
        while (sfRenderWindow_pollEvent(general->window, &general->event) && \
        active != 0 && general->act_scene != ID_CLOSE)
            active = fight_event(general);
    }
    fight_destroy(&fight);
    sfRenderWindow_setView(general->window, general->views.actual_view);
}