/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include <time.h>
#include "my_rpg.h"

sfSprite *init_texture_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

void init_all(game_t *game)
{
    srand(time(NULL));
    init_enemy(game);
    if (game->is_invalid)
        return;
    init_projectile(game);
    init_inventory(game);
    init_controls(game);
}
