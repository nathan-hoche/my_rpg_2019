/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** initialize fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"


static void init_buttons(fight_buttons_t *fight_but, csfml_t *general)
{
    sfIntRect rect_but_atk = {342, 0, 342, 80};
    sfIntRect rect_but_def = {0, 0, 342, 80};
    sfVector2f pos_txt_atk = {1000 + 62, 820};
    sfVector2f pos_txt_def = {570 + 65, 820};

    fight_but->size_butt_atk = (sfVector2f) {342, 80};
    fight_but->size_butt_def = (sfVector2f) {342, 80};
    fight_but->pos_butt_atk = (sfVector2f) {1000, 820};
    fight_but->pos_butt_def = (sfVector2f) {570, 820};
    fight_but->texture = sfTexture_createFromFile(FIGHT_BUTTONS_TEXTR, NULL);
    fight_but->button_atk = make_sprite(fight_but->texture);
    fight_but->button_def = make_sprite(fight_but->texture);
    sfSprite_setTextureRect(fight_but->button_atk, rect_but_atk);
    sfSprite_setTextureRect(fight_but->button_def, rect_but_def);
    sfSprite_setPosition(fight_but->button_atk, fight_but->pos_butt_atk);
    sfSprite_setPosition(fight_but->button_def, fight_but->pos_butt_def);
    fight_but->txt_atk = make_text(general->font_itim, "ATTACK", \
        pos_txt_atk, 60);
    fight_but->txt_def = make_text(general->font_itim, "DEFEND", \
        pos_txt_def, 60);
}

void fight_initialize(fight_scene_t *fight, csfml_t *general)
{
    sfVector2f pos_txt_msg = {740, 860};

    fight->updater = 1;
    fight->turn_state = 0;
    fight->back.tx_back = make_texture(FIGHT_BACK_1);
    fight->back.sp_back = make_sprite(fight->back.tx_back);
    initialize_areas(general, fight);
    init_buttons(&fight->fight_buttons, general);
    fight->info_area.txt_wait = \
        make_text(general->font_itim, "Enemy turn ...", pos_txt_msg, 80);
    fight->player_sp = sfSprite_copy(general->player.player);
    sfSprite_setTextureRect(fight->player_sp, (sfIntRect) {0, 128, 64, 64});
    sfSprite_setScale(fight->player_sp, (sfVector2f) {4, 4});
    sfSprite_setPosition(fight->player_sp, (sfVector2f) {500, 420});

    ///// TEST /////

    sfTexture *txtr_enemy = sfTexture_createFromFile("src/corona.png", NULL);
    fight->enemy_sp = make_sprite(txtr_enemy);
    sfSprite_setTexture(fight->enemy_sp, txtr_enemy, sfTrue);
    sfSprite_setScale(fight->enemy_sp, (sfVector2f) {0.2, 0.2});
    sfSprite_setPosition(fight->enemy_sp, (sfVector2f) {1200, 480});

    fight->player_stats.hp = 42;
    fight->player_stats.atk = 2;
    fight->player_stats.armor = 24;
    fight->player_stats.speed = 1;

    fight->enemy_stats.hp = 66;
    fight->enemy_stats.atk = 6;
    fight->enemy_stats.armor = 12;
    fight->enemy_stats.speed = 1;
}