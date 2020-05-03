/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight end
*/

#include "my_rpg.h"
#include "struct.h"

int check_end(fight_scene_t *fight, game_menu_t *game, csfml_t *general)
{
    if (fight->player.stats.hp <= 0) {
        general->act_scene = ID_CLOSE;
        sfMusic_pause(general->music.fight);
        display_outro(general->window, &game->outro);
        return (1);
    } else if (fight->enemy.stats.hp <= 0) {
        if (fight->type_enemy == 1) {
            general->act_scene = ID_CLOSE;
            sfMusic_pause(general->music.fight);
            display_end_game(general->window, &game->outro);
            display_outro(general->window, &game->outro);
        }
        return (1);
    }
    return (0);
}