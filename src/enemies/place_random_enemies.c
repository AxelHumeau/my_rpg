/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** place randomly enemies
*/

#include "my_rpg.h"

sfVector2f random_place(scene_t *scene, int i)
{
    int width = rand() % WIDTH;
    int height = rand() % HEIGHT;
    sfVector2f random;

    if (width < 100)
        width += 150;
    if (width > 1500)
        width -= 150;
    if (height < 100)
        height += 100;
    if (height > 800)
        height -= 100;
    random = (sfVector2f)
    {width + WIDTH * scene->tab[i]->pos.x,
    height + HEIGHT * scene->tab[i]->pos.y};
    return (random);
}