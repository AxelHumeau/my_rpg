/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clic
*/

#include "my_rpg.h"

void draw_button(button_t *button, game_t *game)
{
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    sfRenderWindow_drawText(game->window, button->text, NULL);
    if (button->sec_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, button->sec_sprite, NULL);
    if (button->ter_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, button->ter_sprite, NULL);
    if (button->auxiliary_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, button->auxiliary_sprite,
        NULL);
}

void update_button(button_t *button, game_t *game)
{
    if (is_mouse_over_button(button, game->window))
        button->rect.top = button->rect.height;
    else
        button->rect.top = 0;
    if (is_button_pressed(button, game->window)) {
        button->status = 1;
        button->rect.top = button->rect.height * 2;
    } else if (button->status == 1) {
        button->status = 0;
        button->rect.top = 0;
        button->callback(game, button);
    }
    sfSprite_setPosition(button->sprite, button->pos);
    sfText_setPosition(button->text, (sfVector2f)
    {button->pos.x + button->rect.width,
    button->pos.y + button->rect.height});
    draw_button(button, game);
}
