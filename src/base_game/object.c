/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game_object
*/

#include "my_rpg.h"

static void set_bar_to_null(game_object_t *obj)
{
    obj->hp_bar = NULL;
    obj->hp_bar_background = NULL;
    obj->mana_bar = NULL;
    obj->mana_bar_background = NULL;
    obj->xp_bar = NULL;
    obj->xp_bar_background = NULL;
}

game_object_t *create_game_object(sfTexture *assets_texture,
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    obj->texture = assets_texture;
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->is_disabled = 0;
    obj->clock = NULL;
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    if (scale.x != -1 && scale.y != -1)
        sfSprite_setScale(obj->sprite, scale);
    obj->position = pos;
    sfSprite_setPosition(obj->sprite, obj->position);
    obj->type = UI;
    set_bar_to_null(obj);
    return (obj);
}

void destroy_game_object(game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    if (obj->hp_bar != NULL) {
        sfRectangleShape_destroy(obj->hp_bar);
        sfRectangleShape_destroy(obj->hp_bar_background);
    }
    if (obj->mana_bar != NULL) {
        sfRectangleShape_destroy(obj->mana_bar);
        sfRectangleShape_destroy(obj->mana_bar_background);
    }
    if (obj->xp_bar != NULL) {
        sfRectangleShape_destroy(obj->xp_bar);
        sfRectangleShape_destroy(obj->xp_bar_background);
    }
    free(obj);
}

void update_default(game_object_t *obj, game_t *game)
{
    if (!obj->is_disabled) {
        sfSprite_setPosition(obj->sprite, obj->position);
        sfRenderWindow_drawSprite(game->window, obj->sprite, NULL);
    }
}
