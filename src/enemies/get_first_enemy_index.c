/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** get_first_enemy_index
*/

#include "my_rpg.h"

int get_first_enemy_index(scene_t *scene)
{
    static int index = 0;

    if (index != 0)
        return index;
    for (int i = 0; scene->objects[i] != NULL &&
    scene->objects[i]->type != ENEMY; i++)
        index++;
    return index;
}
