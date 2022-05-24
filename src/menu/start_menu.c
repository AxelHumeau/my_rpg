/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** start_menu
*/

#include "my_rpg.h"

static void display_how_to_play(game_t *game, button_t *button)
{
    CURRENT_SCENE->buttons[0]->is_disabled = 1;
    CURRENT_SCENE->buttons[1]->is_disabled = 1;
    CURRENT_SCENE->buttons[2]->is_disabled = 1;
    CURRENT_SCENE->buttons[3]->is_disabled = 1;
    CURRENT_SCENE->buttons[8]->is_disabled = 0;
    CURRENT_SCENE->objects[1]->is_disabled = 0;
}

static void back(game_t *game, button_t *button)
{
    CURRENT_SCENE->buttons[0]->is_disabled = 0;
    CURRENT_SCENE->buttons[1]->is_disabled = 0;
    CURRENT_SCENE->buttons[2]->is_disabled = 0;
    CURRENT_SCENE->buttons[3]->is_disabled = 0;
    CURRENT_SCENE->buttons[4]->is_disabled = 1;
    CURRENT_SCENE->buttons[5]->is_disabled = 1;
    CURRENT_SCENE->buttons[6]->is_disabled = 1;
    CURRENT_SCENE->buttons[7]->is_disabled = 1;
    CURRENT_SCENE->buttons[8]->is_disabled = 1;
    CURRENT_SCENE->objects[1]->is_disabled = 1;
}

static void create_menu_button(scene_t *scene, game_t *game)
{
    scene->buttons[0] = create_button(create_vector((WIDTH - 340) / 4,
        HEIGHT / 3), &next_scene, STANDARD_B,
        create_text("PLAY", game->font, NULL, 30));
    scene->buttons[1] = create_button(create_vector((WIDTH - 340) / 4 * 3,
        HEIGHT / 3), &display_how_to_play, STANDARD_B,
        create_text("HELP", game->font, NULL, 30));
    scene->buttons[2] = create_button(create_vector((WIDTH - 340) / 4,
        HEIGHT / 6 * 4), &display_settings, STANDARD_B,
        create_text("SETTINGS", game->font, NULL, 30));
    scene->buttons[3] = create_button(create_vector((WIDTH - 340) / 4 * 3,
        HEIGHT / 6 * 4), &quit_game, STANDARD_B,
        create_text("QUIT", game->font, NULL, 30));
    create_settings_button(scene, 4, game->font);
    scene->buttons[8] = create_button(create_vector(0, HEIGHT / 10 * 9),
        &back, SMALL_B, create_text("X", game->font, NULL, 30));
    scene->buttons[8]->is_disabled = 1;
    scene->buttons[9] = NULL;
}

static void create_menu_object(scene_t *scene, game_t *game)
{
    scene->objects[0] = create_game_object(game->assets_texture, ORIGIN_V,
    create_rect(405, 0, 400, 225), create_vector(4, 4));
    scene->objects[1] = create_game_object(game->assets_texture, ORIGIN_V,
    create_rect(805, 0, 400, 225), create_vector(4, 4));
    scene->objects[1]->is_disabled = 1;
    scene->objects[2] = NULL;
}

scene_t *create_menu_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->objects = malloc(sizeof(game_object_t) * 3);
    scene->buttons = malloc(sizeof(button_t) * 10);
    create_menu_button(scene, game);
    create_menu_object(scene, game);
    scene->music = sfMusic_createFromFile("ressources/overwatch_intro.ogg");
    sfMusic_setLoop(scene->music, sfTrue);
    sfMusic_play(scene->music);
    return scene;
}
