/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** melee animation
*/

#include "my_rpg.h"

static sfFloatRect type_of_attack(sfFloatRect player_r, game_object_t *player)
{
    if (player->state == WALK_UP)
        player_r.top -= player->reach;
    if (player->state == WALK_DOWN)
        player_r.height += player->reach;
    if (player->state == WALK_LEFT)
        player_r.left -= player->reach;
    if (player->state == WALK_RIGHT)
        player_r.width += player->reach;
    if (player->state == IDLE) {
        player_r.top -= player->reach;
        player_r.height += (player->reach);
        player_r.left -= player->reach;
        player_r.width += (player->reach);
    }
    return (player_r);
}

static void is_enemy_hurt(game_object_t *player, game_t *game,
game_object_t *enemy)
{
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(enemy->sprite);
    sfFloatRect player_r = sfSprite_getGlobalBounds(player->sprite);

    player_r = type_of_attack(player_r, player);
    if ((test_colliding(player_r, enemy_r)) && !enemy->is_disabled) {
        enemy->hp -= player->damage;
        if (player->hp + (player->damage / 2) < 150)
            player->hp += player->damage / 2.5;
    }
}

void player_melee(game_t *game, game_object_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && player->idle
    && game->inventory->is_inventory_active == false) {
        player->idle = false;
        for (int i = get_first_enemy_index(CURRENT_SCENE);
            CURRENT_SCENE->objects[i]->type == ENEMY; i++)
            is_enemy_hurt(player, game, CURRENT_SCENE->objects[i]);
        if (player->state == WALK_UP)
            make_player_anim(game, 12, 0.02, 1263);
        if (player->state == WALK_DOWN)
            make_player_anim(game, 12, 0.02, 1390);
        if (player->state == WALK_LEFT)
            make_player_anim(game, 12, 0.02, 1325);
        if (player->state == WALK_RIGHT)
            make_player_anim(game, 12, 0.02, 1455);
        if (player->state == IDLE)
            make_player_anim(game, 6, 0.1, 368);
        if (player->state == HIT || player->state == SHOOT)
            player->idle = true;
    }
}
