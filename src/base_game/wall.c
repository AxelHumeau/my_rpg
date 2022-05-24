/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** wall
*/

#include "my_rpg.h"

game_object_t *create_wall(sfVector2f pos, sfIntRect rect, sfTexture *texture)
{
    game_object_t *wall = create_game_object(texture, pos,
        rect, SCALE(4));

    wall->type = COLLITION;
    return wall;
}

void update_collision(game_object_t *obj, game_t *game)
{
    if (obj->is_disabled)
        return;
    sfSprite_setPosition(obj->sprite, obj->position);
    sfRenderWindow_drawSprite(game->window, obj->sprite, NULL);
    hard_collision(obj, game);
}
