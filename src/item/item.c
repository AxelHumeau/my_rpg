/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_inventory.c
*/

#include <stdio.h>
#include "my_rpg.h"

bool is_in_tab(game_object_t *obj)
{
    if (obj->position.x >= 0 && obj->position.x <= 1600 &&
        obj->position.y >= 0 && obj->position.y <= 900)
        return (true);
    return (false);
}

bool add_item_pos(game_t *game, game_object_t *enemy,
game_object_t *item, int i)
{
    if (game->is_camera_moving == true)
        i = 0;
    if (i >= 4)
        return (false);
    if (item->idle == false) {
        return (false);
    }
    item->position.x = enemy->position.x - 15;
    item->position.y = enemy->position.y - 5;
    sfSprite_setPosition(item->sprite, item->position);
    item->idle = false;
    game->item_spawned += 1;
    enemy->state = 1;
    i += 1;
    return (true);
}

void draw_item_enable(game_object_t *item, game_t *game, scene_t *scene)
{
    if (item->idle == false) {
        sfSprite_setPosition(item->sprite, item->position);
        sfRenderWindow_drawSprite(game->window, item->sprite, NULL);
        get_item(scene->objects[scene->nb_obj], item, game);
    }
}

void update_item(game_object_t *item, game_t *game)
{
    bool is_dead = false;
    int index = 0;
    static int i = 0;
    scene_t *scene = game->scenes[game->current_scene];

    if (game->is_camera_moving) {
        item->idle = true;
        i = 0;
    }
    index = get_first_enemy_index(scene);
    for (; scene->objects[index]->type == ENEMY; index++) {
        if (scene->objects[index]->hp <= 0 && is_in_tab(scene->objects[index])
        && scene->objects[index]->state != 1)
            is_dead = add_item_pos(game, scene->objects[index], item, i);
        if (is_dead)
            break;
    }
    draw_item_enable(item, game, scene);
}

int create_item(scene_t *scene, int i, int index, game_t *game)
{
    int j;

    for (j = 0; j < 4; j++) {
        scene->objects[index] = create_game_object(game->assets_texture,
        (sfVector2f) {-100, -100}, (sfIntRect) {887, 425, 32, 32}, NO_SCALE);
        scene->objects[index]->type = ITEM;
        scene->objects[index]->idle = true;
        scene->objects[index]->hp = 20;
        scene->objects[index]->damage = 1;
        scene->objects[index]->attk_speed = 0;
        index += 1;
    }
    return (j);
}
