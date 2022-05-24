/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** draw_enemy_on_top
*/

#include "my_rpg.h"

void draw_enemy_on_top(game_object_t *player, game_t *game)
{
    int i = get_first_enemy_index(CURRENT_SCENE);
    game_object_t *enemy;
    sfFloatRect rect_player;
    sfFloatRect rect_enemy;

    for (; i <= CURRENT_SCENE->nb_obj &&
    CURRENT_SCENE->objects[i]->type == ENEMY; i++) {
        enemy = CURRENT_SCENE->objects[i];
        rect_enemy = sfSprite_getGlobalBounds(enemy->sprite);
        rect_player = sfSprite_getGlobalBounds(player->sprite);
        if (!enemy->is_disabled &&
        test_colliding(rect_player, rect_enemy) &&
        (rect_enemy.top - rect_player.top) > rect_player.height / 4)
            sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
    }
}
