/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** mouse
*/

#include "my_rpg.h"

sfBool is_mouse_over_button(button_t *button, sfRenderWindow *window)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(window);
    if (is_btwn(pos.x, button->pos.x, button->pos.x +
    button->rect.width * 2) &&
    is_btwn(pos.y, button->pos.y, button->pos.y + button->rect.height * 2))
        return sfTrue;
    else
        return sfFalse;
}

sfBool is_button_pressed(button_t *button, sfRenderWindow *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        return is_mouse_over_button(button, window);
    return sfFalse;
}
