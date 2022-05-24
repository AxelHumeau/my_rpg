/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** sort_object
*/

#include "my_rpg.h"

static void find_min_and_swap(game_object_t **objects, int index)
{
    int index_min = index;
    game_object_t *tmp;

    for (int i = index + 1; objects[i]; i++) {
        if (objects[index_min]->type > objects[i]->type) {
            tmp = objects[index_min];
            objects[index_min] = objects[i];
            objects[i] = tmp;
            index_min = i;
        }
    }
}

void sort_object(game_object_t **objects)
{
    for (int i = 0; objects[i]; i++)
        find_min_and_swap(objects, i);
}
