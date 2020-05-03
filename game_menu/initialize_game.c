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

static void initialize_entity(game_menu_t *game, csfml_t *general)
{
    sfVector2f pos = {32 * 34, 32 * 29};

    game->entity = malloc(sizeof(entity_t) * 2);
    game->entity[0].txtr = sfTexture_createFromFile("src/fire_32x21.png", NULL);
    game->entity[0].rect = (sfIntRect) {0, 0, 21, 32};
    game->entity[0].sp = make_sprite(game->entity[0].txtr);
    sfSprite_setOrigin(game->entity[0].sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(game->entity[0].sp, game->entity[0].rect);
    sfSprite_setPosition(game->entity[0].sp, pos);
    game->entity[1].txtr = sfTexture_createFromFile("src/fire_32x19.png", NULL);
    game->entity[1].rect = (sfIntRect) {0, 0, 21, 32};
    game->entity[1].sp = make_sprite(game->entity[0].txtr);
    sfSprite_setOrigin(game->entity[1].sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(game->entity[1].sp, game->entity[1].rect);
    pos = (sfVector2f) {32 * 34, 32 * 29};
    sfSprite_setPosition(game->entity[1].sp, pos);
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
    initialize_inventory(general, game);
    initialize_graphical_stats(&game->inventory, general);
    initialize_texts(&game->inventory.stats, general);
    initialize_npc(game);
    init_message_box(game, general);
    initialize_view(general);
    game->on_fight = 0;
    game->inter = 0;
    game->inter_lock = 0;
    initialize_entity(game, general);
    game->adventure_step = 0;
}