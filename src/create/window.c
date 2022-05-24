/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_window
*/

#include "my_rpg.h"

sfRenderWindow *create_window(char const *title, unsigned int height,
unsigned int width)
{
    sfVideoMode video_mode = {height, width, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
    title, sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
