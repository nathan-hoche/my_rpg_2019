/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** flame_particule
*/

#include "my_rpg.h"
#include "my.h"
#include "struct.h"

void initialize_entity(entity_t *small_flame, entity_t *big_flame, \
csfml_t *general)
{
    sfVector2f pos = {32 * 34, 32 * 29};

    small_flame->txtr = sfTexture_createFromFile(PARTICULE_FIRE_1, NULL);
    small_flame->rect = (sfIntRect) {0, 0, 21, 32};
    small_flame->sp = make_sprite(small_flame->txtr);
    sfSprite_setOrigin(small_flame->sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(small_flame->sp, small_flame->rect);
    sfSprite_setPosition(small_flame->sp, pos);
    big_flame->txtr = sfTexture_createFromFile(PARTICULE_FIRE_2, NULL);
    big_flame->rect = (sfIntRect) {0, 0, 21, 32};
    big_flame->sp = make_sprite(small_flame->txtr);
    sfSprite_setOrigin(big_flame->sp, (sfVector2f) {-7, 21});
    sfSprite_setTextureRect(big_flame->sp, big_flame->rect);
    pos = (sfVector2f) {32 * 34, 32 * 29};
    sfSprite_setPosition(big_flame->sp, pos);
    small_flame->clock = sfClock_create();
    big_flame->clock = sfClock_create();
}

void destroy_entity(entity_t *small_flame, entity_t *big_flame)
{
    sfSprite_destroy(small_flame->sp);
    sfSprite_destroy(big_flame->sp);
    sfTexture_destroy(small_flame->txtr);
    sfTexture_destroy(big_flame->txtr);
    sfClock_destroy(small_flame->clock);
    sfClock_destroy(big_flame->clock);
}

static void entity_animation(entity_t *small_flame, entity_t *big_flame)
{
    sfInt64 time;

    time = sfClock_getElapsedTime(small_flame->clock).microseconds;
    if (time >= 40000) {
        small_flame->rect.left += 23;
        if (small_flame->rect.left > 160)
            small_flame->rect.left = 0;
        sfSprite_setTextureRect(small_flame->sp, small_flame->rect);
        sfClock_restart(small_flame->clock);
    }
    time = sfClock_getElapsedTime(big_flame->clock).microseconds;
    if (time >= 50000) {
        big_flame->rect.left += 23;
        if (big_flame->rect.left > 140)
            big_flame->rect.left = 0;
        sfSprite_setTextureRect(big_flame->sp, big_flame->rect);
        sfClock_restart(big_flame->clock);
    }
}

void display_flame_particule(entity_t *small_flame, entity_t *big_flame, \
sfRenderWindow *window)
{
    int first_flame[2][2] = {{32 * 33, 32 * 29}, {32 * 32, 32 * 20}};
    int second_flame[6][2] = {{32 * 45, 32 * 25}, {32 * 45, 32 * 29}, \
    {32 * 46, 32 * 25}, {32 * 46, 32 * 29}, {32 * 47, 32 * 25}, \
    {32 * 47, 32 * 29}};

    entity_animation(small_flame, big_flame);
    for (int i = 0; i != 2; i++) {
        sfSprite_setPosition(small_flame->sp, (sfVector2f) \
        {first_flame[i][0], first_flame[i][1]});
        sfRenderWindow_drawSprite(window, small_flame->sp, NULL);
    }
    for (int j = 0; j != 6; j++) {
        sfSprite_setPosition(big_flame->sp, (sfVector2f) \
        {second_flame[j][0], second_flame[j][1] + 7});
        sfRenderWindow_drawSprite(window, big_flame->sp, NULL);
    }
}