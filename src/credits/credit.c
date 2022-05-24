/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** credit
*/

#include "my_rpg.h"

void switch_to_credits(game_t *game)
{
    sfMusic_stop(CURRENT_SCENE->music);
    game->current_scene = CREDITS;
    sfMusic_play(CURRENT_SCENE->music);
}

void skip_ending(game_t *game, button_t *button)
{
    CURRENT_SCENE->objects[4]->is_disabled = 1;
    for (int i = 0; i < 4; i++)
        CURRENT_SCENE->objects[i]->state = !PARALLAX_MOVING;
    button->is_disabled = 1;
    CURRENT_SCENE->objects[5]->is_disabled = 0;
    CURRENT_SCENE->buttons[1]->is_disabled = 1;
}

static button_t *create_credit_button(game_t *game)
{
    char text_str[] = "Congratulations !\n\n"
                "You managed to get the\n"
                "three holy pods,\n"
                "assembling the tripod,\n"
                "and with its power\n"
                "you rescued Washy\n"
                "the washing machine.\n\n"
                "And now, Washy continues to\n"
                "travel around the world,\n"
                "looking for new adventures,\n"
                "and new clothes to wash.";
    sfText *text = create_text(text_str, game->font, &sfWhite, 60);
    button_t *text_button;

    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    text_button = create_button(create_vector((WIDTH / 3) + 75, HEIGHT + 300),
        &do_nothing, create_rect(0, 0, 0, 0), text);
    return text_button;
}

scene_t *create_credit_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->objects = malloc(sizeof(game_object_t *) * 7);
    set_parallax(scene, 0, game);
    scene->objects[4] = create_washing_machine(game);
    scene->objects[5] = create_game_object(game->assets_texture, ORIGIN_V,
    (sfIntRect) {0, 977, 400, 225}, SCALE(4));
    scene->objects[5]->type = OTHER;
    scene->objects[5]->is_disabled = 1;
    scene->objects[6] = NULL;
    scene->buttons = malloc(sizeof(button_t *) * 3);
    scene->buttons[0] = create_button(create_vector(WIDTH - 340, 0),
    &skip_ending, STANDARD_B, create_text("SKIP", game->font, NULL, 30));
    scene->buttons[1] = create_credit_button(game);
    scene->buttons[2] = NULL;
    scene->music = sfMusic_createFromFile("ressources/camping-night.ogg");
    return scene;
}
