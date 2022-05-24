/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemies
*/

#include "my_rpg.h"

static void is_enemie_hurt(game_t *game, game_object_t *enemy)
{
    for (int i = 0; i < PROJ_NB - 1; i++) {
        if (test_colliding(sfSprite_getGlobalBounds(enemy->sprite),
        sfSprite_getGlobalBounds(game->proj[i]->sprite)) &&
        !game->proj[i]->is_enemy && game->proj[i]->is_shooting) {
            enemy->hp -= game->proj[i]->damage;
            reset_bubble(game, i);
            enemy->triggered = true;
        }
    }
    if (enemy->hp <= 0) {
        enemy->is_disabled = true;
        if (PLAYER_FROM_GAME->xp < 100)
            PLAYER_FROM_GAME->xp += enemy->xp;
        if (PLAYER_FROM_GAME->xp > 100)
            PLAYER_FROM_GAME->xp += 100 - PLAYER_FROM_GAME->xp;
        sfMusic_stop(game->sound_effects[3]);
        sfMusic_play(game->sound_effects[3]);
    }
}

void update_enemies(game_object_t *enemy, game_t *game)
{
    if (enemy->is_disabled)
        return;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    if (game->is_camera_moving) {
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
        return;
    }
    enemies_idle(enemy, game);
    sfSprite_move(enemy->sprite, enemy->normalize);
    enemies_animation(enemy, game);
    is_enemie_hurt(game, enemy);
    if (enemy->hp > 0)
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    if (enemy->triggered)
        update_bars(enemy, game->window);
}
