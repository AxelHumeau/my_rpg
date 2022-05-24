/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is player near to player
*/

#include "my_rpg.h"

int is_player_near(game_t *game, game_object_t *enemy)
{
    sfVector2f enemie_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f player_pos = sfSprite_getPosition(PLAYER_FROM_GAME->sprite);

    if (enemie_pos.x + enemy->reach > player_pos.x &&
        enemie_pos.x - enemy->reach < player_pos.x &&
        enemie_pos.y + enemy->reach > player_pos.y &&
        enemie_pos.y - enemy->reach < player_pos.y)
        return (true);
    return (false);
}