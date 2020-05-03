/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** flame_particule
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void initialize_entity(game_menu_t *game, csfml_t *general)
{
    sfVector2f pos = {32 * 34, 32 * 29};

    game->entity = NULL;
    game->entity = malloc(sizeof(entity_t) * 2);
    game->entity[0].txtr = sfTexture_createFromFile(PARTICULE_FIRE_1, NULL);
    game->entity[0].rect = (sfIntRect) {0, 0, 21, 32};
    game->entity[0].sp = make_sprite(game->entity[0].txtr);
    sfSprite_setOrigin(game->entity[0].sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(game->entity[0].sp, game->entity[0].rect);
    sfSprite_setPosition(game->entity[0].sp, pos);
    game->entity[1].txtr = sfTexture_createFromFile(PARTICULE_FIRE_2, NULL);
    game->entity[1].rect = (sfIntRect) {0, 0, 21, 32};
    game->entity[1].sp = make_sprite(game->entity[0].txtr);
    sfSprite_setOrigin(game->entity[1].sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(game->entity[1].sp, game->entity[1].rect);
    pos = (sfVector2f) {32 * 34, 32 * 29};
    sfSprite_setPosition(game->entity[1].sp, pos);
    game->entity[0].clock = sfClock_create();
    game->entity[1].clock = sfClock_create();
}

void destroy_entity(game_menu_t *game)
{
    sfSprite_destroy(game->entity[0].sp);
    sfSprite_destroy(game->entity[1].sp);
    sfTexture_destroy(game->entity[0].txtr);
    sfTexture_destroy(game->entity[1].txtr);
    sfClock_destroy(game->entity[0].clock);
    sfClock_destroy(game->entity[1].clock);
}

void entity_animation(game_menu_t *game)
{
    sfInt64 time;

    time = sfClock_getElapsedTime(game->entity[0].clock).microseconds;
    if (time >= 50000) {
        game->entity[0].rect.top += 19;
        if (game->entity[0].rect.top > 133)
            game->entity[0].rect.top = 0;
        sfClock_restart(game->entity[0].clock);
    }
    time = sfClock_getElapsedTime(game->entity[1].clock).microseconds;
    if (time >= 75000) {
        game->entity[1].rect.top += 21;
        if (game->entity[1].rect.top > 133)
            game->entity[1].rect.top = 0;
        sfClock_restart(game->entity[1].clock);
    }
}