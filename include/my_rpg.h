/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg prototypes
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define ICON_WINDOW "src/icon.png"

#define PLAYER_TEXTURE_1 "src/player/male.png"
#define PLAYER_TEXTURE_2 "src/player/female.png"

#define MUSIC_MENU "src/sounds/menu.ogg"
#define MUSIC_BEACH "src/sounds/beach.ogg"
#define MUSIC_ADVEN "src/sounds/adventure.ogg"
#define MUSIC_MENU_PLAY (1)
#define CLICK_SOUND "src/sounds/click.ogg"

#define BUT_1_TXTR "src/buttons/button.png"
#define BUT_1_SIZ_X (285)
#define BUT_1_SIZ_Y (110)

#define BUT_2_TXTR "src/buttons/button_set.png"

#define FONT_1 "src/font_itim.ttf"
#define BACKGROUND_1 "src/backs/space.png"
#define BACKGROUND_2 "src/backs/island.jpg"

#define MAP_SP_SHEET "src/tile.png"

#define MAP_L01_FILE "map/map_layer01.txt"
#define MAP_L02_FILE "map/map_layer02.txt"

#define MAP_GROUND_1 "src/backs/water.jpg"

#define CONFIG_INVENTORY_FILE "src/config.txt"

#define INVENTORY_FILE "src/inventory.png"
#define SWORD_FILE "src/items/weapons/sword_start.png"
#define SHIELD_FILE "src/items/armor/shield_start.png"
#define HELMET_FILE "src/items/armor/helmet_start.png"
#define ARMOR_FILE "src/items/armor/bust_start.png"
#define PANTS_FILE "src/items/armor/pants_start.png"
#define FIGHT_BACK_1 "src/backs/fight_back.png"

#define FIGHT_SOUND_SWORD "src/sounds/sound_sword.ogg"

#define FIGHT_SHIELD "src/fight/shield.png"
#define FIGHT_SLASH "src/fight/cut.png"

#define PARTICULE_FIRE_1 "src/particles/fire_32x21.png"
#define PARTICULE_FIRE_2 "src/particles/fire_32x19.png"

#define INTRO_BACKGROUND "src/intro.png"
#define END_GAME "src/memory.png"

#define SPEED_BOSS (80)

#define DEFAULT_FX_LEVEL (60)
#define DEFAULT_MUSIC_LEVEL (60)

#define BASE_WIDTH (1920)
#define BASE_HEIGHT (1080)

#define NB_SCENE (2)
#define ID_CLOSE (0)
#define ID_START_MENU (1)
#define ID_GAME (2)

#define NB_START_MENU_B (4)

#define NB_SET_MENU_B (5)

#define NB_TEXTURE_PLAYER (2)

#define PLAYER_SP_SIZ_X (64)
#define PLAYER_SP_SIZ_Y (64)

#define BLOCK_SIZE_X (32)
#define BLOCK_SIZE_Y (32)

#define CAM_DEFAULT_ZOOM (0.48)

#define INVENTORY_ID_SIZE (7)

#define SWORD_POS_X (5)
#define SWORD_POS_Y (2)
#define SHIELD_POS_X (65)
#define SHIELD_POS_Y (6)
#define HELMET_POS_X (115)
#define HELMET_POS_Y (4)
#define ARMOR_POS_X (162)
#define ARMOR_POS_Y (1)
#define PANTS_POS_X (216)

#define END_NPC_ACT (1)

#define FIGHT_BUT_TEXTR "src/buttons/fight_buttons.png"
#define MUSIC_FIGHT "src/sounds/battle.ogg"

#define STAT_DATA (3)

#define NB_NPC (5)

#define NPC_01 "src/npc/npc_03.png"
#define NPC_02 "src/npc/npc_02.png"
#define NPC_03 "src/npc/npc_04.png"
#define NPC_04 "src/npc/npc_01.png"
#define NPC_05 "src/npc/npc_05.png"

void game_menu(csfml_t *page);

void start_menu(csfml_t *page);
void start_initialize(start_menu_t *start, csfml_t *page);
void pause_menu(csfml_t *page);
void initialize_window(csfml_t *page);
void init_game_scene(game_scene_t *scene);
void init_player(player_t *player);
void init_game_player(player_t *player, game_scene_t *game_scene);
void init_destroy(player_t *player);
void game_event(csfml_t *general, game_menu_t *game);
void game_music(music_t *music);
void display_player_with_entities(csfml_t *general, game_menu_t *game);
void initialize_game_core(game_menu_t *game, csfml_t *general);
int message_management(game_menu_t *game, csfml_t *general);
int camera_fight_zoom(game_menu_t *game, csfml_t *general);
int action_start_button(csfml_t *page);
int action_quit_button(csfml_t *page);
int action_settings_button(csfml_t *page);
int action_howtoplay_button(csfml_t *page);
void action_button_hover(button_t *button, csfml_t *core);
void check_buttons_hover(start_menu_t *start, csfml_t *page);
int button_obj_is_hover(button_t *button, sfRenderWindow *window);
void settings_initialize(settings_menu_t *set, csfml_t *page);
void free_game_ressources(game_menu_t *game);
int **display_optimization(char **map, player_t *playr, int **view_dist);
int manage_before_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step);
int manage_after_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step);
int fight_controller(game_menu_t *game, csfml_t *general, npc_t *npc);

int manage_after_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step);
int manage_before_fight(game_menu_t *game, csfml_t *general, \
npc_t *npc, int step);
int after_fight(game_menu_t *game, csfml_t *general, npc_t *npc);
int before_fight(game_menu_t *game, csfml_t *general, npc_t *npc);
int fight_controller(game_menu_t *game, csfml_t *general, npc_t *npc);

void initialize_entity(entity_t *small_flame, entity_t *big_flame, \
csfml_t *general);
void display_flame_particule(entity_t *small_flame, entity_t *big_flame, \
sfRenderWindow *window);
void destroy_entity(entity_t *small_flame, entity_t *big_flame);

//-> SETTINGS_MENU <-////////////////////////////

void change_volume(music_t *music);
int action_plus_fx(csfml_t *page);
int action_minus_fx(csfml_t *page);
int action_plus_music(csfml_t *page);
int action_minus_music(csfml_t *page);
int action_returning(csfml_t *page);
void settings(csfml_t *page);

/////////////////////////////////////////////////

void how_to_play(csfml_t *page);

int event_skin(csfml_t *page);
void skin(csfml_t *page);
int pause_check_button(csfml_t *page, pause_menu_t *pause);

//-> FIGHT_SYSTEM <-/////////////////////////////

int fight_management(game_menu_t *game, csfml_t *general);
void fight_initialize(fight_scene_t *fight, csfml_t *general, npc_t *npc);
void fight_core(csfml_t *general, game_menu_t *game, npc_t *npc);
void fight_destroy(fight_scene_t *fight);
void display_infos_areas(fight_scene_t *fight, sfRenderWindow *window);
void turn_core(fight_scene_t *fight, sfRenderWindow *window);
void initialize_areas(csfml_t *general, fight_scene_t *fight);
void display_stats_valors(info_area_t *area, stats_t *player, stats_t *enemy);
void fight_attack_animation(fighter_t *striker, fighter_t *target, \
fight_scene_t *fight, csfml_t *general);
void fight_button_hover(fight_button_t *button);
void fight_button_no_hover(fight_button_t *button);
void fight_button_clicked(fight_button_t *button);
int check_end(fight_scene_t *fight, game_menu_t *game, csfml_t *general);

//-> INVENTORY_SYSTEM <-/////////////////////////

int initialize_inventory(csfml_t *general, game_menu_t *game);
void initialize_items(items_t *items);
void manage_inventory_event(csfml_t *page, inventory_t *inventory);
void display_items(sfRenderWindow *window, items_t *items);
void free_inventory(inventory_t *inventory);
void set_inventory_pos(csfml_t *page, inventory_t *inventory);
void display_inventory(csfml_t *general, game_menu_t *game);

//-> PLAYER_SYSTEM <-/////////////////////////

void player_core(csfml_t *general, game_menu_t *game);
void camera_view(game_menu_t *game, csfml_t *page);
int player_collision_core(int key, player_t *player, game_menu_t *game);
void player_animation(player_t *player);
void player_movement(player_t *player);
void destroy_player(player_t *player);
void player_orientation(sfEvent event, player_t *player, game_menu_t *game);
void check_collisions_with_npc(player_t *player, npc_t *npc);
void player_gps(player_t *player);

void display_map_core(game_menu_t *game, csfml_t *general);

//-> NPC_SYSTEM <-///////////////////////////////

void initialize_npc(game_menu_t *game);
int check_npc_collision(npc_t *npc, player_t *player);
void manage_npc_actions(csfml_t *general, game_menu_t *game);
void npc_gps(npc_t *npc);
int action_move_npc(npc_t *npc, player_t *player, int dist, int dir);
int action_wait_npc(npc_t *npc, player_t *player, float seconds);
void action_npc_focus_player(player_t *player, npc_t *npc);

int patern_npc_01(game_menu_t *game, csfml_t *general, npc_t *npc);
int patern_npc_02(game_menu_t *game, csfml_t *general, npc_t *npc);
int patern_npc_04(game_menu_t *game, csfml_t *general, npc_t *npc);

void set_good_npc_01(npc_t *npc, npc_texture_t *npc_txtr);
void set_good_npc_02(npc_t *npc, npc_texture_t *npc_txtr);
void set_good_npc_03(npc_t *npc, npc_texture_t *npc_txtr);
void set_bad_npc_01(npc_t *npc, npc_texture_t *npc_txtr);
void set_bad_npc_02(npc_t *npc, npc_texture_t *npc_txtr);

/////////////////////////////////////////////////

int init_message_box(game_menu_t *game, csfml_t *general);
int action_message(char **message, game_menu_t *game, csfml_t *general);
int display_message_box(game_menu_t *game, csfml_t *general);
char *initialize_stats(inventory_t *inventory, char *buf, char *line, \
csfml_t *general);
void initialize_graphical_stats(inventory_t *inventory, csfml_t *general);
void display_status(csfml_t *general, stats_panel_t *stats);
void free_stats(stats_panel_t *stats);
void initialize_texts(stats_panel_t *stats, csfml_t *general);
void set_stats_pos(inventory_t *inventory, csfml_t *general);

void display_intro(sfRenderWindow *window, game_menu_t *game);
void display_outro(sfRenderWindow *window, outro_t *outro);
void begin_cinematics(intro_t *intro, csfml_t *general, \
outro_t *outro);
void display_end_game(sfRenderWindow *window, outro_t *outro);

#endif /* !MY_RPG_H_ */