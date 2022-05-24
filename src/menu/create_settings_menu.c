/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** create_settings_menu
*/

#include "my_rpg.h"

static void create_plus_and_minus(scene_t *scene, int index, sfFont *font)
{
    scene->buttons[index] = create_button(create_vector(
        WIDTH / 5 * 3, HEIGHT / 4),
        &increase_volume, SMALL_B, create_text("+", font, NULL, 30));
    scene->buttons[index + 1] = create_button(create_vector(
        WIDTH / 5 * 4, HEIGHT / 4),
        &decrease_volume, SMALL_B, create_text("-", font, NULL, 30));
}

void create_settings_button(scene_t *scene, int index, sfFont *font)
{
    sfText *text = create_text("SOUND", font, &sfWhite, 40);
    sfText *percent_text;

    create_plus_and_minus(scene, index, font);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4);
    scene->buttons[index + 2] = create_button(create_vector(
        WIDTH / 5, HEIGHT / 4 + 40), &do_nothing,
        create_rect(0, 0, 0, 0), text);
    percent_text = sfText_copy(text);
    sfText_setString(percent_text, "100%");
    scene->buttons[index + 3] = create_button(create_vector(
        WIDTH / 20 * 14.8, HEIGHT / 4 + 40),
        &do_nothing, create_rect(0, 0, 0, 0), percent_text);
    for (int i = 0; i < 4; i++)
        scene->buttons[index + i]->is_disabled = 1;
}
