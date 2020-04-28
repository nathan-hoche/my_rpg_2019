/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

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

void display_infos_areas(fight_scene_t *fight, sfRenderWindow *window)
{
    display_life_area(&fight->info_area, window);
    display_stats_area(&fight->info_area, window);
}