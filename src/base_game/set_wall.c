/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** set_wall
*/

#include "my_rpg.h"

int set_walls_left(scene_t *scene, int i, int index, game_t *game)
{
    if (scene->tab[i]->op_left) {
        scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x) *
        WIDTH, GET_TAB(i, pos.y) * HEIGHT), (sfIntRect) {GET_TAB(i, rect.left),
        GET_TAB(i, rect.top) + 225, 16, 80}, game->assets_texture);
        scene->objects[index + 1] = create_wall(create_vector(GET_TAB(i, pos.x)
        * WIDTH, GET_TAB(i, pos.y) * HEIGHT + 160 * 4), (sfIntRect)
        {GET_TAB(i, rect.left), GET_TAB(i, rect.top) + 160 + 225, 16, 64},
        game->assets_texture);
        return 2;
    }
    scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x) *
    WIDTH, GET_TAB(i, pos.y) * HEIGHT), (sfIntRect) {GET_TAB(i, rect.left),
    GET_TAB(i, rect.top) + 225 + 900, 16, 225}, game->assets_texture);
    return 1;
}

int set_walls_right(scene_t *scene, int i, int index, game_t *game)
{
    if (scene->tab[i]->op_right) {
        scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x) *
        WIDTH + WIDTH - 64, GET_TAB(i, pos.y) * HEIGHT), (sfIntRect)
        {GET_TAB(i, rect.left) + GET_TAB(i, rect.width) - 16,
        GET_TAB(i, rect.top) + 450, 16, 80}, game->assets_texture);
        scene->objects[index + 1] = create_wall(create_vector(GET_TAB(i, pos.x)
        * WIDTH + WIDTH - 64,
        GET_TAB(i, pos.y) * HEIGHT + 160 * 4),
        (sfIntRect) {GET_TAB(i, rect.left) + GET_TAB(i, rect.width) - 16,
        GET_TAB(i, rect.top) + 160 + 450, 16, 64}, game->assets_texture);
        return 2;
    }
    scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x)
    * WIDTH + WIDTH - 64,
    GET_TAB(i, pos.y) * HEIGHT), (sfIntRect) {GET_TAB(i, rect.left) +
    GET_TAB(i, rect.width) - 16, GET_TAB(i, rect.top) + 450 + 900, 16, 225},
    game->assets_texture);
    return 1;
}

int set_walls_up(scene_t *scene, int i, int index, game_t *game)
{
    if (scene->tab[i]->op_up) {
        scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x) *
        WIDTH, GET_TAB(i, pos.y) * HEIGHT), (sfIntRect) {GET_TAB(i, rect.left),
        GET_TAB(i, rect.top) + 675, 160, 16}, game->assets_texture);
        scene->objects[index + 1] = create_wall(create_vector(GET_TAB(i, pos.x)
        * WIDTH + 240 * 4, GET_TAB(i, pos.y) * HEIGHT),
        (sfIntRect) {GET_TAB(i, rect.left) + 240,
        GET_TAB(i, rect.top) + 675, 160, 16}, game->assets_texture);
        return 2;
    }
    scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x) *
    WIDTH, GET_TAB(i, pos.y) * HEIGHT), (sfIntRect) {GET_TAB(i, rect.left),
    GET_TAB(i, rect.top) + 675 + 900, 400, 16}, game->assets_texture);
    return 1;
}

int set_walls_down(scene_t *scene, int i, int index, game_t *game)
{
    if (scene->tab[i]->op_down) {
        scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x)
        * WIDTH, GET_TAB(i, pos.y) * HEIGHT + HEIGHT - 64),
        (sfIntRect) {GET_TAB(i, rect.left), GET_TAB(i, rect.top)
        + GET_TAB(i, rect.height) - 16 + 900, 160, 16}, game->assets_texture);
        scene->objects[index + 1] = create_wall(create_vector(GET_TAB(i, pos.x)
        * WIDTH + 240 * 4, GET_TAB(i, pos.y) * HEIGHT + HEIGHT - 64),
        (sfIntRect) {GET_TAB(i, rect.left) + 240,
        GET_TAB(i, rect.top) + GET_TAB(i, rect.height) - 16 + 900, 160, 16},
        game->assets_texture);
        return 2;
    }
    scene->objects[index] = create_wall(create_vector(GET_TAB(i, pos.x)
    * WIDTH, GET_TAB(i, pos.y) * HEIGHT + HEIGHT - 64),
    (sfIntRect) {GET_TAB(i, rect.left), GET_TAB(i, rect.top) +
    GET_TAB(i, rect.height) - 16 + 900 + 900, 400, 16}, game->assets_texture);
    return 1;
}
