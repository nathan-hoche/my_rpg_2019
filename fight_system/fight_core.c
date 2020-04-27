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

static void display_life_area(info_area_t *area, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, area->player_life_area.life_txt, NULL);
    sfRenderWindow_drawText(window, area->enemy_life_area.life_txt, NULL);
    sfRenderWindow_drawText(window, area->player_life_area.name, NULL);
    sfRenderWindow_drawText(window, area->enemy_life_area.name, NULL);
    sfRenderWindow_drawText(window, area->player_life_area.life_val, NULL);
    sfRenderWindow_drawText(window, area->enemy_life_area.life_val, NULL);
}

static void display_stats_area(info_area_t *area, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, area->player_stats_area.name, NULL);
    sfRenderWindow_drawText(window, area->player_stats_area.atk_txt, NULL);
    sfRenderWindow_drawText(window, area->player_stats_area.atk_val, NULL);
    sfRenderWindow_drawText(window, area->player_stats_area.shld_txt, NULL);
    sfRenderWindow_drawText(window, area->player_stats_area.shld_val, NULL);
    sfRenderWindow_drawText(window, area->enemy_stats_area.name, NULL);
    sfRenderWindow_drawText(window, area->enemy_stats_area.atk_txt, NULL);
    sfRenderWindow_drawText(window, area->enemy_stats_area.atk_val, NULL);
    sfRenderWindow_drawText(window, area->enemy_stats_area.shld_txt, NULL);
    sfRenderWindow_drawText(window, area->enemy_stats_area.shld_val, NULL);
}

static void fight_display(fight_scene_t *fight, sfRenderWindow *window, \
csfml_t *general)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, fight->back.sp_back, NULL);
    display_life_area(&fight->info_area, window);
    display_stats_area(&fight->info_area, window);
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