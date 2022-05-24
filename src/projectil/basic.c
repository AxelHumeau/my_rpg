/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** basic projectile
*/

#include "my_rpg.h"
#include <stdio.h>

void reset_bubble(game_t *game, int current)
{
    game->proj[current]->is_shooting = false;
    game->proj[current]->splashing = true;
    sfSprite_setPosition(game->proj[current]->splash,
    sfSprite_getPosition(game->proj[current]->sprite));
    game->proj[current]->auto_target = false;
}

static void splash_animation(game_t *game, int current)
{
    sfSprite_setTextureRect(game->proj[current]->splash,
    game->proj[current]->splash_rect);
    game->proj[current]->splash_rect.left -=
    game->proj[current]->splash_rect.width;
    if (game->proj[current]->splash_rect.left < 0) {
        game->proj[current]->splash_rect.top -=
        game->proj[current]->splash_rect.height;
        game->proj[current]->splash_rect.left = 131;
    }
    if (game->proj[current]->splash_rect.top < 2272) {
        game->proj[current]->splash_rect.top = 2439;
        game->proj[current]->splashing = false;
    }
}

static void move_bubble(game_t *game, int current)
{
    if (sfClock_getElapsedTime(game->proj[current]->clock).microseconds / 100 >
    10) {
        game->proj[current]->normalize = (sfVector2f)
        {game->proj[current]->move_v.x / game->proj[current]->magnitude,
        game->proj[current]->move_v.y / game->proj[current]->magnitude};
        game->proj[current]->normalize.x *= game->proj[current]->speed.x;
        game->proj[current]->normalize.y *= game->proj[current]->speed.y;
        sfSprite_move(game->proj[current]->sprite,
        game->proj[current]->normalize);
    }
    game->proj[current]->position =
    sfSprite_getPosition(game->proj[current]->sprite);
    if (game->proj[current]->position.x > WIDTH ||
        game->proj[current]->position.y > HEIGHT ||
        game->proj[current]->position.x < 0 ||
        game->proj[current]->position.y < 0)
        reset_bubble(game, current);
}

static void is_bubble_counter(game_t *game, int current)
{
    for (int i = 0; game->proj[i]; i++) {
        if (test_colliding(
        sfSprite_getGlobalBounds(game->proj[current]->sprite),
        sfSprite_getGlobalBounds(game->proj[i]->sprite)) &&
        game->proj[i]->is_shooting && game->proj[current]->is_enemy !=
        game->proj[i]->is_enemy && game->proj[current]->is_shooting) {
            reset_bubble(game, current);
            reset_bubble(game, i);
            sfMusic_stop(game->sound_effects[2]);
            sfMusic_play(game->sound_effects[2]);
        }
    }
}

void update_bubble(game_t *game, int current)
{
    if (game->proj[current]->is_shooting)
        move_bubble(game, current);
    if (game->proj[current]->is_shooting)
        sfRenderWindow_drawSprite(game->window, game->proj[current]->sprite,
        NULL);
    else if (game->proj[current]->splashing) {
        splash_animation(game, current);
        sfRenderWindow_drawSprite(game->window, game->proj[current]->splash,
        NULL);
    }
    is_bubble_counter(game, current);
    if (game->proj[current]->auto_target) {
        game->proj[current]->target = PLAYER_FROM_GAME->position;
        get_vector_move(game,
        sfSprite_getPosition(game->proj[current]->sprite), current);
    }
}
