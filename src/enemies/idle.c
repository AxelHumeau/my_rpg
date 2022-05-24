/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** idle of enemies
*/

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"

static sfVector2f get_vector_movement(sfVector2f position, sfVector2f speed,
int x, int y)
{
    sfVector2f move;
    sfVector2f normalize;
    float magnitude;

    move.x = x - position.x;
    move.y = y - position.y;
    magnitude = sqrt(pow(move.x, 2) + pow(move.y, 2));
    normalize = (sfVector2f) {move.x / magnitude, move.y / magnitude};
    normalize.x *= speed.x;
    normalize.y *= speed.y;
    return (normalize);
}

static int get_abscisse(int size, float pos)
{
    int random = rand() % 2;
    int abscisse = 0;
    if (random)
        abscisse = pos - size;
    else
        abscisse = pos + size;
    return (abscisse);
}

static void is_enemies_trigger(game_object_t *enemy, game_t *game)
{
    int x;
    int y;

    if (!enemy->triggered) {
        x = get_abscisse(WIDTH, enemy->position.x);
        y = get_abscisse(HEIGHT, enemy->position.y);
        enemy->normalize = get_vector_movement(enemy->position, enemy->speed,
        x, y);
    } else {
        x = PLAYER_FROM_GAME->position.x;
        y = PLAYER_FROM_GAME->position.y;
        enemy->normalize = get_vector_movement(enemy->position, enemy->speed,
        x, y);
    }
}

void enemies_idle(game_object_t *enemy, game_t *game)
{
    if (!(rand() % 10000)) {
        enemy->normalize.x = 0;
        enemy->normalize.y = 0;
    }
    if (get_time_clock(enemy->clock) - enemy->saved_idle >
        ((rand() % 300) / 10) || enemy->triggered) {
        enemy->saved_idle = get_time_clock(enemy->clock);
        if ((rand() % 4) && !enemy->triggered)
            return;
        is_enemies_trigger(enemy, game);
    }
    if (!enemy->triggered || (enemy->triggered && !is_player_near(game, enemy))
    || (enemy->triggered && enemy->cac == 0)) {
        enemy->position.x += enemy->normalize.x;
        enemy->position.y += enemy->normalize.y;
    }
}
