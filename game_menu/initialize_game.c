/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop the game
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

static void initialize_view(csfml_t *gen)
{
    gen->views.default_view = sfRenderWindow_getDefaultView(gen->window);
    gen->views.actual_view = sfView_copy(gen->views.default_view);
    sfView_zoom(gen->views.actual_view, CAM_DEFAULT_ZOOM);
    gen->views.default_player_view = sfView_copy(gen->views.actual_view);
    sfRenderWindow_setView(gen->window, gen->views.actual_view);
}

void game_music(music_t *music)
{
    music->fight = sfMusic_createFromFile(MUSIC_FIGHT);
    sfMusic_setLoop(music->fight, sfTrue);
    sfMusic_setVolume(music->fight, DEFAULT_MUSIC_LEVEL);
    music->adven = sfMusic_createFromFile(MUSIC_ADVEN);
    sfMusic_setLoop(music->adven, sfTrue);
    sfMusic_setVolume(music->adven, DEFAULT_MUSIC_LEVEL);
}

void game_events_messages(game_menu_t *game, csfml_t *general)
{
    game->step_one_txt = NULL;
    
    game->step_one_txt = malloc(sizeof(char *) * 2);
    game->step_one_txt[0] = my_strdup("I should go and see what's going on \n\
    this village before i continue...");
    game->step_one_txt[1] = NULL;
}

void initialize_game_core(game_menu_t *game, csfml_t *general)
{
    game->game_scene.map_layer01_file = MAP_L01_FILE;
    game->game_scene.map_layer02_file = MAP_L02_FILE;
    init_game_scene(&game->game_scene);
    init_game_player(&general->player, &game->game_scene);
    game->texture_tile = make_texture(MAP_SP_SHEET);
    game->tile = make_sprite(game->texture_tile);
    game->grass = make_texture(MAP_GROUND_1);
    game->back_grass = make_sprite(game->grass);
    initialize_inventory(general, game);
    initialize_graphical_stats(&game->inventory, general);
    initialize_npc(game);
    init_message_box(game, general);
    initialize_view(general);
    game->on_fight = 0;
    game->inter = 0;
    game->inter_lock = 0;
    initialize_entity(&game->small_flame, &game->big_flame, general);
    begin_cinematics(&game->intro, general, &game->outro);
    game_events_messages(game, general);
    game->adventure_step = 1;
}