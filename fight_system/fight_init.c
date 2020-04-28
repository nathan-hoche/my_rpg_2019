/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** initialize fight system core
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

static void init_buttons(fight_buttons_t *fight_buttons, csfml_t *general)
{
    sfIntRect rect_button_atk = {342, 0, 342, 80};
    sfIntRect rect_button_def = {0, 0, 342, 80};
    sfVector2f pos_butt_atk = {1000, 820};
    sfVector2f pos_butt_def = {570, 820};
    sfVector2f pos_txt_atk = {pos_butt_atk.x + 62, pos_butt_atk.y};
    sfVector2f pos_txt_def = {pos_butt_def.x + 65, pos_butt_def.y};

    fight_buttons->texture = \
        sfTexture_createFromFile(FIGHT_BUTTONS_TEXTR, NULL);
    fight_buttons->button_atk = make_sprite(fight_buttons->texture);
    fight_buttons->button_def = make_sprite(fight_buttons->texture);
    sfSprite_setTextureRect(fight_buttons->button_atk, rect_button_atk);
    sfSprite_setTextureRect(fight_buttons->button_def, rect_button_def);
    sfSprite_setPosition(fight_buttons->button_atk, pos_butt_atk);
    sfSprite_setPosition(fight_buttons->button_def, pos_butt_def);
    fight_buttons->txt_atk = make_text(general->font_itim, "ATTACK", \
        pos_txt_atk, 60);
    fight_buttons->txt_def = make_text(general->font_itim, "DEFEND", \
        pos_txt_def, 60);
}

void fight_initialize(fight_scene_t *fight, csfml_t *general)
{
    sfVector2f pos_txt_msg = {740, 860};

    fight->turn_state = 1;
    fight->back.tx_back = make_texture(FIGHT_BACK_1);
    fight->back.sp_back = make_sprite(fight->back.tx_back);
    init_life_area(&fight->info_area, general);
    init_stats_area_player(&fight->info_area.player_stats_area, general);
    init_stats_area_enemy(&fight->info_area.enemy_stats_area, general);
    init_buttons(&fight->fight_buttons, general);
    fight->info_area.txt_wait = \
        make_text(general->font_itim, "Enemy turn ...", pos_txt_msg, 80);
}