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

static void initialize_music(csfml_t *gen)
{
    gen->music.fight = sfMusic_createFromFile(MUSIC_FIGHT);
    sfMusic_setLoop(gen->music.fight, sfTrue);
    sfMusic_setVolume(gen->music.fight, gen->settings.music_lvl);
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
    initialize_view(general);
    initialize_inventory(&game->inventory);
    initialize_npc(game);
    init_message_box(game, general);
    initialize_view(general);
    initialize_music(general);
    game->on_fight = 0;
    game->inter = 0;
    game->inter_lock = 0;
}