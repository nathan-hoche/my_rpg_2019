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
    if (fight->updater == 1) {
        display_stats_valors(&fight->info_area, \
            &fight->player_stats, &fight->enemy_stats);
        fight->updater = 0;
    }
    display_life_area(&fight->info_area, window);
    display_stats_area(&fight->info_area, window);
}

void display_stats_valors(info_area_t *area, stats_t *player, stats_t *enemy)
{
    char *hp_play = my_getnbr(player->hp);
    char *atk_play = my_getnbr(player->atk);
    char *armor_play = my_getnbr(player->armor);
    char *hp_enem = my_getnbr(enemy->hp);
    char *atk_enem = my_getnbr(enemy->atk);
    char *armor_enem = my_getnbr(enemy->armor);

    sfText_setString(area->player_life_area.life_val, hp_play);
    free(hp_play);
    sfText_setString(area->player_stats_area.atk_val, atk_play);
    free(atk_play);
    sfText_setString(area->player_stats_area.shld_val, armor_play);
    free(armor_play);
    sfText_setString(area->enemy_life_area.life_val, hp_enem);
    free(hp_enem);
    sfText_setString(area->enemy_stats_area.atk_val, atk_enem);
    free(atk_enem);
    sfText_setString(area->enemy_stats_area.shld_val, armor_enem);
    free(armor_enem);
}