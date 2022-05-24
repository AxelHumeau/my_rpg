/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** collision
*/

#include "my_rpg.h"
#include <math.h>

bool test_colliding(sfFloatRect rect_1, sfFloatRect rect_2)
{
    return ((is_btwn(rect_1.left, rect_2.left, rect_2.left + rect_2.width) ||
        is_btwn(rect_1.left + rect_1.width, rect_2.left, rect_2.left +
        rect_2.width) || is_btwn(rect_1.left + rect_1.width / 2,
        rect_2.left, rect_2.left + rect_2.width)) &&
        (is_btwn(rect_1.top, rect_2.top, rect_2.top + rect_2.height) ||
        is_btwn(rect_1.top + rect_1.height, rect_2.top, rect_2.top +
        rect_2.height) || is_btwn(rect_1.top + rect_1.height / 2,
        rect_2.top, rect_2.top + rect_2.height)));
}

static void cancel_movement(sfFloatRect rect1, sfFloatRect rect_tmp,
game_object_t *object)
{
    float dif_x = 0;
    float dif_y = 0;

    dif_x = rect_tmp.left + rect_tmp.width - rect1.left;
    if (fabs(dif_x) > rect_tmp.width)
        dif_x = rect_tmp.left - (rect1.left + rect1.width);
    dif_y = rect_tmp.top + rect_tmp.height - rect1.top;
    if (fabs(dif_y) > rect_tmp.height)
        dif_y = rect_tmp.top - (rect1.top + rect1.height);
    object->position.x += (fabs(dif_x) <= object->speed.x ? -dif_x : 0);
    object->position.y += (fabs(dif_y) <= object->speed.y ? -dif_y : 0);
}

void hard_collision(game_object_t *object, game_t *game)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(object->sprite);
    sfFloatRect rect_tmp;

    for (int i = get_first_enemy_index(CURRENT_SCENE);
    CURRENT_SCENE->objects[i] != NULL; i++) {
        if (CURRENT_SCENE->objects[i]->is_disabled)
            continue;
        rect_tmp = sfSprite_getGlobalBounds(CURRENT_SCENE->objects[i]->sprite);
        if (test_colliding(rect_tmp, rect1) && !game->is_camera_moving)
            cancel_movement(rect1, rect_tmp, CURRENT_SCENE->objects[i]);
    }
}
