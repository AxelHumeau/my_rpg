/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** clocks
*/

#include "my_rpg.h"

sfClock **create_clocks(void)
{
    sfClock **clocks = malloc(sizeof(sfClock *) * NB_CLOCKS);

    for (int i = 0; i < NB_CLOCKS; i++)
        clocks[i] = sfClock_create();
    return clocks;
}

void destroy_clocks(sfClock **clocks)
{
    for (int i = 0; i < NB_CLOCKS; i++)
        sfClock_destroy(clocks[i]);
    free(clocks);
}

float get_time_clock(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}
