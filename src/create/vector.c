/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_vector
*/

#include "my_rpg.h"

sfVector2f create_vector(float x, float y)
{
    sfVector2f point = {x, y};

    return (point);
}

sfIntRect create_rect(int x, int y, int width, int height)
{
    sfIntRect rect = {x, y, width, height};

    return (rect);
}
