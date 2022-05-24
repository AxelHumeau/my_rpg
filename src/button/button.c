/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

void init_sprite_button(button_t *button, sfVector2f position, sfIntRect rect)
{
    button->texture = sfTexture_createFromFile("ressources/Assets.png", NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    button->pos = position;
    button->rect = rect;
    button->is_disabled = 0;
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, create_vector(2, 2));
}

button_t *create_button(sfVector2f position, callbacks_func_t *func,
sfIntRect rect, sfText *text)
{
    button_t *button = malloc(sizeof(button_t));

    init_sprite_button(button, position, rect);
    button->callback = func;
    button->text = text;
    sfText_setPosition(button->text, create_vector(position.x +
        button->rect.width, position.y + button->rect.height));
    button->status = 0;
    button->sec_sprite = NULL;
    button->ter_sprite = NULL;
    button->auxiliary_sprite = NULL;
    return (button);
}

void destroy_button(button_t *button)
{
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
    sfText_destroy(button->text);
    if (button->sec_sprite != NULL)
        sfSprite_destroy(button->sec_sprite);
    if (button->ter_sprite != NULL)
        sfSprite_destroy(button->ter_sprite);
    if (button->auxiliary_sprite != NULL)
        sfSprite_destroy(button->auxiliary_sprite);
    free(button);
}

void set_tertiary_sprite(button_t *button, sfIntRect rect)
{
    button->ter_sprite = sfSprite_create();
    button->auxiliary_sprite = sfSprite_create();
    sfVector2f pos = button->pos;

    pos.y += 100;
    pos.x -= 20;
    button->ter_rect = rect;
    button->ter_rect.top = 55;
    button->ter_rect.width = 0;
    sfSprite_setTexture(button->ter_sprite, button->texture, sfFalse);
    sfSprite_setTextureRect(button->ter_sprite, rect);
    sfSprite_setPosition(button->ter_sprite, pos);
    sfSprite_setScale(button->ter_sprite, create_vector(1.5, 1.5));
    sfSprite_setTexture(button->auxiliary_sprite, button->texture, sfFalse);
    sfSprite_setTextureRect(button->auxiliary_sprite, button->ter_rect);
    pos.y -= 4;
    sfSprite_setPosition(button->auxiliary_sprite, pos);
    sfSprite_setScale(button->auxiliary_sprite, create_vector(1.5, 1.5));
}

void set_secondary_sprite(button_t *button, sfIntRect rect)
{
    button->sec_sprite = sfSprite_create();

    sfSprite_setTexture(button->sec_sprite, button->texture, sfFalse);
    sfSprite_setTextureRect(button->sec_sprite, rect);
    sfSprite_setPosition(button->sec_sprite, button->pos);
    sfSprite_setScale(button->sec_sprite, create_vector(2, 2));
}
