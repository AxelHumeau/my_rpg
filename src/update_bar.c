/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hp_bar
*/

#include "my_rpg.h"

sfRectangleShape *create_rect_bar(sfVector2f position, int width,
    sfColor color, sfVector2f scale)
{
    sfRectangleShape *bar = sfRectangleShape_create();

    sfRectangleShape_setSize(bar, create_vector(width, 10));
    sfRectangleShape_setFillColor(bar, color);
    sfRectangleShape_setOrigin(bar, create_vector(width / 2, 5));
    sfRectangleShape_setPosition(bar, position);
    sfRectangleShape_setScale(bar, scale);
    return bar;
}

void create_hp_bar(game_object_t *object, int is_player)
{
    sfFloatRect rect_object = sfSprite_getGlobalBounds(object->sprite);
    sfVector2f position = {rect_object.left + rect_object.width / 2,
        rect_object.top - 10};
    sfRectangleShape *back_bar = create_rect_bar(position, object->hp,
        sfBlack, is_player ? create_vector(2.06, 2.4) :
        create_vector(1.03, 1.2));
    sfRectangleShape *green_bar = create_rect_bar(position, object->hp,
        sfGreen, is_player ? SCALE(2) : NO_SCALE);

    object->hp_bar = green_bar;
    object->hp_bar_background = back_bar;
}

static void update_player_bar(game_object_t *object, sfRenderWindow *window)
{
    sfVector2f hp_position = {180, 840};

    sfRectangleShape_setSize(object->hp_bar, create_vector(object->hp, 10));
    sfRectangleShape_setPosition(object->hp_bar, hp_position);
    sfRectangleShape_setPosition(object->hp_bar_background, hp_position);
    sfRenderWindow_drawRectangleShape(window, object->hp_bar_background, NULL);
    sfRenderWindow_drawRectangleShape(window, object->hp_bar, NULL);
    sfRectangleShape_setSize(object->mana_bar, create_vector(object->mana,
    10));
    sfRenderWindow_drawRectangleShape(window, object->mana_bar_background,
    NULL);
    sfRenderWindow_drawRectangleShape(window, object->mana_bar, NULL);
    sfRectangleShape_setSize(object->xp_bar, create_vector(object->xp, 10));
    sfRenderWindow_drawRectangleShape(window, object->xp_bar_background, NULL);
    sfRenderWindow_drawRectangleShape(window, object->xp_bar, NULL);
}

static void update_enemy_hp(game_object_t *object, sfRenderWindow *window)
{
    sfFloatRect rect_object = sfSprite_getGlobalBounds(object->sprite);
    sfVector2f position = {rect_object.left + rect_object.width / 2,
        rect_object.top - 10};

    sfRectangleShape_setSize(object->hp_bar, create_vector(object->hp, 10));
    sfRectangleShape_setPosition(object->hp_bar, position);
    sfRectangleShape_setPosition(object->hp_bar_background, position);
    sfRenderWindow_drawRectangleShape(window, object->hp_bar_background, NULL);
    sfRenderWindow_drawRectangleShape(window, object->hp_bar, NULL);
}

void update_bars(game_object_t *object, sfRenderWindow *window)
{
    if (object->type == PLAYER)
        update_player_bar(object, window);
    else
        update_enemy_hp(object, window);
}
