/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** make dirty bubble
*/

#include "my_rpg.h"
#include <stdio.h>

static void auto_dirty_bubble(game_object_t *enemy, game_t *game)
{
    int index = 0;

    for (; game->proj[index + 1]; index++)
        if (!game->proj[index]->shoot && !game->proj[index]->is_shooting)
            break;
    game->proj[index]->rect.left = 251;
    sfSprite_setTextureRect(game->proj[index]->sprite,
    game->proj[index]->rect);
    game->proj[index]->is_shooting = true;
    game->proj[index]->target = PLAYER_FROM_GAME->position;
    game->proj[index]->is_enemy = true;
    game->proj[index]->auto_target = true;
    game->proj[index]->damage = enemy->damage;
    get_vector_move(game, enemy->position, index);
}

static void make_dirty_bubble(game_object_t *enemy, game_t *game)
{
    int index = 0;

    for (; game->proj[index + 1]; index++)
        if (!game->proj[index]->shoot && !game->proj[index]->is_shooting)
            break;
    game->proj[index]->rect.left = 251;
    sfSprite_setTextureRect(game->proj[index]->sprite,
    game->proj[index]->rect);
    game->proj[index]->is_shooting = true;
    game->proj[index]->target = PLAYER_FROM_GAME->position;
    game->proj[index]->is_enemy = true;
    game->proj[index]->damage = enemy->damage;
    get_vector_move(game, enemy->position, index);
}

static void cac_attack(game_object_t *enemy, game_t *game)
{
    enemy->position.x += enemy->normalize.x;
    enemy->position.y += enemy->normalize.y;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    if (test_colliding(sfSprite_getGlobalBounds(enemy->sprite),
    sfSprite_getGlobalBounds(PLAYER_FROM_GAME->sprite)))
        PLAYER_FROM_GAME->hp -= enemy->damage;
}

static void boss_attack(game_object_t *enemy, game_t *game)
{
    int random = rand() % 10;

    if (random <= 5)
        auto_dirty_bubble(enemy, game);
    if (random > 5 && random <= 8)
        make_dirty_bubble(enemy, game);
    if (random == 9)
        cac_attack(enemy, game);
}

void attack_pattern(game_object_t *enemy, game_t *game)
{
    if (enemy->cac == 0)
        cac_attack(enemy, game);
    if (enemy->cac == 1)
        make_dirty_bubble(enemy, game);
    if (enemy->cac >= 2)
        boss_attack(enemy, game);
}
