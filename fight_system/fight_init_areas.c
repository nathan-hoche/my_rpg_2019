/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** initialize fight system areas
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void init_stats_area_player(stats_area_t *stats, csfml_t *general)
{
    sfVector2f pos_name_player = {142, 790};
    sfVector2f pos_atk_txt_player = {20, 870};
    sfVector2f pos_atk_val_player = {222, 870};
    sfVector2f pos_shld_txt_player = {20, 930};
    sfVector2f pos_shld_val_player = {222, 930};

    stats->name = make_text(general->font_itim, "STATS", pos_name_player, 50);
    stats->atk_txt = \
        make_text(general->font_itim, "ATTACK :", pos_atk_txt_player, 40);
    stats->atk_val = \
        make_text(general->font_itim, "0", pos_atk_val_player, 40);
    stats->shld_txt = \
        make_text(general->font_itim, "ARMOR :", pos_shld_txt_player, 40);
    stats->shld_val = \
        make_text(general->font_itim, "0", pos_shld_val_player, 40);
}

static void init_stats_area_enemy(stats_area_t *stats, csfml_t *general)
{
    sfVector2f pos_name_enemy = {1642, 790};
    sfVector2f pos_atk_txt_enemy = {1500, 860};
    sfVector2f pos_atk_val_enemy = {1700, 860};
    sfVector2f pos_shld_txt_enemy = {1500, 930};
    sfVector2f pos_shld_val_enemy = {1700, 930};

    stats->name = make_text(general->font_itim, "STATS", pos_name_enemy, 50);
    stats->atk_txt = \
        make_text(general->font_itim, "ATTACK :", pos_atk_txt_enemy, 40);
    stats->atk_val = make_text(general->font_itim, "0", pos_atk_val_enemy, 40);
    stats->shld_txt = \
        make_text(general->font_itim, "ARMOR :", pos_shld_txt_enemy, 40);
    stats->shld_val = \
        make_text(general->font_itim, "0", pos_shld_val_enemy, 40);
}

static void init_life_area(info_area_t *area, csfml_t *general)
{
    sfVector2f pos_hp_txt_player = {10, 100};
    sfVector2f pos_hp_val_player = {180, 100};
    sfVector2f pos_name_player = {142, 5};
    sfVector2f pos_hp_txt_enemy = {1530, 100};
    sfVector2f pos_hp_val_enemy = {1700, 100};
    sfVector2f pos_name_enemy = {1650, 5};

    area->player_life_area.life_txt = \
        make_text(general->font_itim, "LIFE :", pos_hp_txt_player, 50);
    area->enemy_life_area.life_txt = \
        make_text(general->font_itim, "LIFE :", pos_hp_txt_enemy, 50);
    area->player_life_area.name = \
        make_text(general->font_itim, "YOU", pos_name_player, 50);
    area->enemy_life_area.name = \
        make_text(general->font_itim, "ENEMY", pos_name_enemy, 50);
    area->player_life_area.life_val = \
        make_text(general->font_itim, "0", pos_hp_val_player, 50);
    area->enemy_life_area.life_val = \
        make_text(general->font_itim, "0", pos_hp_val_enemy, 50);
}

void initialize_areas(csfml_t *general, fight_scene_t *fight)
{
    init_life_area(&fight->info_area, general);
    init_stats_area_player(&fight->info_area.player_stats_area, general);
    init_stats_area_enemy(&fight->info_area.enemy_stats_area, general);
}