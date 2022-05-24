/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_parallax
*/

#include "my_rpg.h"

static void shift_parallax(game_object_t *background, sfRenderWindow *window,
float shift)
{
    sfSprite_setTextureRect(background->sprite, background->rect);
    background->rect.left += shift;
    if (background->rect.left > (1200 - background->rect.width))
        background->rect.left = 1;
}

void update_parallax(game_object_t *obj, game_t *game)
{
    static float shift[4] = {0, 3 / 4, 7 / 4, 9 / 4};

    sfRenderWindow_drawSprite(game->window, obj->sprite, NULL);
    if (obj->state != PARALLAX_MOVING)
        return;
    if (get_time_clock(game->clock[obj->type - 3]) > 0.005) {
        shift_parallax(obj, game->window, shift[obj->type - PARALLAX_B]);
        sfClock_restart(game->clock[obj->type - 3]);
    }
}

void set_parallax(scene_t *scene, int index, game_t *game)
{
    scene->objects[index] = create_game_object(game->assets_texture,
    ORIGIN_V, create_rect(0, 1202, 400, 225), SCALE(4));
    scene->objects[index]->type = PARALLAX_B;
    scene->objects[index]->state = PARALLAX_MOVING;
    scene->objects[index + 1] = create_game_object(game->assets_texture,
    create_vector(0, -125), create_rect(0, 1597, 400, 225), SCALE(4));
    scene->objects[index + 1]->type = PARALLAX_M;
    scene->objects[index + 1]->state = PARALLAX_MOVING;
    scene->objects[index + 2] = create_game_object(game->assets_texture,
    create_vector(0, -125), create_rect(0, 1822, 400, 225), SCALE(4));
    scene->objects[index + 2]->type = PARALLAX_F;
    scene->objects[index + 2]->state = PARALLAX_MOVING;
    scene->objects[index + 3] = create_game_object(game->assets_texture,
    ORIGIN_V, create_rect(0, 2047, 400, 225), SCALE(4));
    scene->objects[index + 3]->type = PARALLAX_G;
    scene->objects[index + 3]->state = PARALLAX_MOVING;
    for (int i = index; i < 4 + index; i++)
        sfSprite_setPosition(scene->objects[i]->sprite,
        scene->objects[i]->position);
}
