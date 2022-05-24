/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** disable_non_near_objects
*/

#include "my_rpg.h"

void disable_non_near_objects(game_object_t *object)
{
    int border[4] = {-WIDTH, 2 * WIDTH, -HEIGHT, 2 * HEIGHT};

    if (object->type >= PARALLAX_B)
        return;
    if (object->type == ENEMY) {
        if (object->hp <= 0)
            return;
        border[0] = 0;
        border[1] = WIDTH;
        border[2] = 0;
        border[3] = HEIGHT;
    }
    if (!(is_btwn_f(object->position.x, border[0], border[1]) &&
    is_btwn_f(object->position.y, border[2], border[3])))
        object->is_disabled = 1;
    else
        object->is_disabled = 0;
}
