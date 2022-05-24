/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game_over
*/

#include "my_rpg.h"

static void create_game_over_button(scene_t *scene, sfFont *font)
{
    scene->buttons = malloc(sizeof(button_t *) * 3);
    scene->buttons[0] = create_button(create_vector((WIDTH - 340) / 2,
        HEIGHT / 6 * 3), &quit_game, STANDARD_B,
        create_text("QUIT", font, NULL, 30));
    scene->buttons[1] = create_button(create_vector(WIDTH / 2, HEIGHT / 6),
        &do_nothing, create_rect(0, 0, 0, 0),
        create_text("GAME OVER", font, &sfWhite, 50));
    scene->buttons[2] = NULL;
}

scene_t *create_game_over_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    create_game_over_button(scene, game->font);
    scene->objects = malloc(sizeof(game_object_t *) * 2);
    scene->objects[0] = create_game_object(game->assets_texture,
    ORIGIN_V, create_rect(0, 737, 400, 225), SCALE(4));
    scene->objects[1] = NULL;
    scene->music = sfMusic_createFromFile("ressources/oh no cringe.ogg");
    sfMusic_setLoop(scene->music, sfFalse);
    sfMusic_setVolume(scene->music, 60);
    return scene;
}
