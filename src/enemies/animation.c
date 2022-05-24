/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemies animation
*/

#include "my_rpg.h"

void enemies_animation(game_object_t *enemy, game_t *game)
{
    if (get_time_clock(enemy->clock) - enemy->saved_anim >
        enemy->animation_speed) {
        enemy->rect.left += enemy->rect.width;
        if (enemy->rect.left > enemy->rect.width * (enemy->animation - 1))
            enemy->rect.left = 0;
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        enemy->saved_anim = get_time_clock(enemy->clock);
    }
    if (get_time_clock(enemy->clock) - enemy->saved_atk > enemy->attk_speed) {
        if (is_player_near(game, enemy)) {
            attack_pattern(enemy, game);
            enemy->triggered = true;
        }
        enemy->saved_atk = get_time_clock(enemy->clock);
    }
}