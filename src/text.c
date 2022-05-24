/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** text
*/

#include "my_rpg.h"

sfText *create_text(const char *str, sfFont *font, sfColor *color, int size)
{
    sfText *text = sfText_create();
    sfFloatRect rect;

    sfText_setString(text, str);
    sfText_setFont(text, font);
    if (!color)
        sfText_setColor(text, sfBlack);
    else
        sfText_setColor(text, *color);
    sfText_setCharacterSize(text, size);
    rect = sfText_getGlobalBounds(text);
    sfText_setOrigin(text, create_vector(rect.left + rect.width / 2.0f,
        rect.top + rect.height / 2.0f));
    return text;
}
