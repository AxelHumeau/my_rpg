/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** scene
*/

#include "my_rpg.h"
#include "scene_creator.h"
#include "update_func.h"

scene_t **create_scenes(game_t *game)
{
    scene_t **scenes = malloc(sizeof(scene_t*) * NB_SCENES);

    for (int i = 0; i < NB_SCENES; i++) {
        scenes[i] = SCENES_CREATOR[i](game);
    }
    return scenes;
}

void refresh_scene(game_t *game)
{
    scene_t *scene = game->scenes[game->current_scene];
    int i;

    if (game->current_scene == HUB)
        move_camera(scene, game,
        check_player_position(PLAYER_FROM_GAME, game));
    for (i = 0; scene->objects[i] && (scene->objects[i]->type == UI ||
    scene->objects[i]->type == COLLITION); i++)
        UPDATE[scene->objects[i]->type](scene->objects[i], game);
    display_framebuffer(game);
    for (; scene->objects[i] != NULL; i++) {
        disable_non_near_objects(scene->objects[i]);
        UPDATE[scene->objects[i]->type](scene->objects[i], game);
    }
    for (int i = 0; scene->buttons[i]; i++)
        if (!scene->buttons[i]->is_disabled)
            update_button(scene->buttons[i], game);
    if (game->pods_collected > 3 && game->current_scene == HUB)
        switch_to_credits(game);
}

void destroy_scenes(scene_t *scene)
{
    if (scene == NULL)
        return;
    for (int i = 0; scene->buttons[i] != NULL; i++)
        destroy_button(scene->buttons[i]);
    free(scene->buttons);
    for (int i = 0; scene->objects[i] != NULL; i++)
        destroy_game_object(scene->objects[i]);
    free(scene->objects);
    sfMusic_destroy(scene->music);
    free(scene);
}

void destroy_all_scenes(scene_t **scenes)
{
    for (int i = 0; i != NB_SCENES; i++)
        destroy_scenes(scenes[i]);
    free(scenes);
}
