/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** camera
*/

#include "my_rpg.h"

int check_player_position(game_object_t *player, game_t *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);

    if (game->is_camera_moving)
        return -1;
    if (rect.left > WIDTH)
        return TO_RIGHT;
    if (rect.left + rect.width < 0)
        return TO_LEFT;
    if (rect.top > HEIGHT)
        return TO_UP;
    if (rect.top + rect.height < 0)
        return TO_DOWN;
    return -1;
}

static void move_object(scene_t *scene, int direction)
{
    for (int i = 0; scene->objects[i] != NULL; i++) {
        if (direction == TO_RIGHT)
            scene->objects[i]->position.x -= SPEED_CAM;
        if (direction == TO_LEFT)
            scene->objects[i]->position.x += SPEED_CAM;
        if (direction == TO_UP)
            scene->objects[i]->position.y -= SPEED_CAM;
        if (direction == TO_DOWN)
            scene->objects[i]->position.y += SPEED_CAM;
    }
}

void move_camera(scene_t *scene, game_t *game, int dir)
{
    static int direction = 0;
    static int progress[4] = {0, 0, 0, 0};

    if (dir == -1 && !game->is_camera_moving)
        return;
    if (dir != -1) {
        clear_framebuffer(game->framebuffer);
        direction = dir;
    }
    game->is_camera_moving = true;
    if (get_time_clock(game->clock[CAM_C]) > 0.001) {
        move_object(scene, direction);
        progress[direction] += SPEED_CAM;
        sfClock_restart(game->clock[CAM_C]);
    }
    if (progress[direction] >=
    (direction == TO_LEFT || direction == TO_RIGHT ? WIDTH : HEIGHT)) {
        progress[direction] = 0;
        game->is_camera_moving = false;
    }
}
