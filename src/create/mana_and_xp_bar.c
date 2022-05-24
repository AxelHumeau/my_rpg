/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create mana and xp bar
*/

#include "my_rpg.h"

void create_mana_bar(game_object_t *object, int is_player)
{
    sfVector2f position = {130, 870};
    sfRectangleShape *back_bar = create_rect_bar(position, object->mana,
        sfBlack, is_player ? create_vector(2.06, 2.4) :
        create_vector(1.03, 1.2));
    sfRectangleShape *blue_bar = create_rect_bar(position, object->mana,
        sfColor_fromRGB(49, 246, 220), is_player ? SCALE(2) : NO_SCALE);

    object->mana_bar = blue_bar;
    object->mana_bar_background = back_bar;
}

void create_xp_bar(game_object_t *object, int is_player)
{
    sfVector2f position = {80, 890};
    sfRectangleShape *back_bar = create_rect_bar(position, 100,
        sfBlack, is_player ? create_vector(2.06, 2.4) :
        create_vector(1.03, 1.2));
    position.x -= 50;
    sfRectangleShape *yellow_bar = create_rect_bar(position, object->xp,
        sfColor_fromRGB(189, 236, 60), is_player ? SCALE(2) : NO_SCALE);

    object->xp_bar = yellow_bar;
    object->xp_bar_background = back_bar;
}
