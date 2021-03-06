/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** initialize fight system core
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void init_fight_enemy(fight_scene_t *fight, csfml_t *general, \
npc_t *npc)
{
    fight->enemy.sp = sfSprite_copy(npc->sp);
    sfSprite_setScale(fight->enemy.sp, (sfVector2f) {4, 4});
    sfSprite_setTextureRect(fight->enemy.sp, (sfIntRect) {0, 64, 64, 64});
    fight->enemy.pos = (sfVector2f) {1200, 590};
    sfSprite_setPosition(fight->enemy.sp, fight->enemy.pos);
    fight->enemy.stats.hp = npc->stats.hp;
    fight->enemy.stats.atk = npc->stats.atk;
    fight->enemy.stats.armor = npc->stats.armor;
    fight->enemy.stats.speed = npc->stats.speed;
    fight->enemy.def = sfFalse;
    if (npc->stats.speed == SPEED_BOSS)
        fight->type_enemy = 1;
    else
        fight->type_enemy = 0;
    sfSprite_setOrigin(fight->enemy.sp, (sfVector2f) {32, 48});
}

static void init_fight_player(fight_scene_t *fight, csfml_t *general)
{
    fight->player.sp = sfSprite_copy(general->player.player);
    sfSprite_setTextureRect(fight->player.sp, (sfIntRect) {0, 128, 64, 64});
    sfSprite_setScale(fight->player.sp, (sfVector2f) {4, 4});
    fight->player.pos = (sfVector2f) {720, 590};
    sfSprite_setPosition(fight->player.sp, fight->player.pos);
    fight->player.stats.hp = general->player.stats.hp;
    fight->player.stats.atk = general->player.stats.atk;
    fight->player.stats.armor = general->player.stats.armor;
    fight->player.stats.speed = general->player.stats.speed;
    fight->player.def = sfFalse;
    fight->player.stats.name = general->player.stats.name;
    sfSprite_setOrigin(fight->player.sp, (sfVector2f) {32, 48});
}

static void init_attacks(fight_scene_t *fight, csfml_t *general)
{
    fight->attacks.txtr_shield = \
        sfTexture_createFromFile(FIGHT_SHIELD, NULL);
    fight->attacks.txtr_sword = \
        sfTexture_createFromFile(FIGHT_SLASH, NULL);
    fight->attacks.sword_slash = sfSprite_create();
    fight->attacks.sword_slash = make_sprite(fight->attacks.txtr_sword);
    fight->attacks.sword_slash_rect = (sfIntRect) {0, 0, 192, 192};
    sfSprite_setScale(fight->attacks.sword_slash, (sfVector2f) {2, 2});
    sfSprite_setTextureRect(fight->attacks.sword_slash, \
        fight->attacks.sword_slash_rect);
    fight->attacks.shield = sfSprite_create();
    fight->attacks.shield = make_sprite(fight->attacks.txtr_shield);
    sfSprite_setScale(fight->attacks.shield, (sfVector2f) {1.2, 1.2});
}

static void init_buttons(fight_scene_t *fight, csfml_t *general)
{
    sfIntRect rect_but_atk = {342, 0, 342, 80};
    sfIntRect rect_but_def = {0, 0, 342, 80};

    fight->button_atk.size = (sfVector2f) {342, 80};
    fight->button_def.size = (sfVector2f) {342, 80};
    fight->button_atk.pos = (sfVector2f) {1000, 820};
    fight->button_def.pos = (sfVector2f) {570, 820};
    fight->tx_buttons = sfTexture_createFromFile(FIGHT_BUT_TEXTR, NULL);
    fight->button_atk.sp = make_sprite(fight->tx_buttons);
    fight->button_def.sp = make_sprite(fight->tx_buttons);
    sfSprite_setTextureRect(fight->button_atk.sp, rect_but_atk);
    sfSprite_setTextureRect(fight->button_def.sp, rect_but_def);
    sfSprite_setPosition(fight->button_atk.sp, fight->button_atk.pos);
    sfSprite_setPosition(fight->button_def.sp, fight->button_def.pos);
    fight->button_atk.txt = make_text(general->font_itim, "ATTACK", \
    (sfVector2f) {1000 + 62, 820}, 60);
    fight->button_def.txt = make_text(general->font_itim, "DEFEND", \
    (sfVector2f) {570 + 65, 820}, 60);
    fight->button_atk.state = 0;
}

void fight_initialize(fight_scene_t *fight, csfml_t *general, npc_t *npc)
{
    sfVector2f pos_txt_msg = {740, 860};

    fight->updater = 1;
    fight->turn_state = 0;
    fight->atk_step = 0;
    fight->back.tx_back = make_texture(FIGHT_BACK_1);
    fight->back.sp_back = make_sprite(fight->back.tx_back);
    initialize_areas(general, fight);
    init_buttons(fight, general);
    fight->info_area.txt_wait = \
        make_text(general->font_itim, "Enemy turn ...", pos_txt_msg, 80);
    init_fight_enemy(fight, general, npc);
    init_fight_player(fight, general);
    init_attacks(fight, general);
    fight->fx_sword_atk.buf = \
        sfSoundBuffer_createFromFile(FIGHT_SOUND_SWORD);
    fight->fx_sword_atk.sound = sfSound_create();
    sfSound_setBuffer(fight->fx_sword_atk.sound, fight->fx_sword_atk.buf);
    sfSound_setVolume(fight->fx_sword_atk.sound, general->settings.fx_lvl);
    fight->button_def.state = 0;
}