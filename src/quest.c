/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** quest
*/

#include "my_rpg.h"

button_t *create_quest_button(sfFont *font)
{
    sfColor gold = {255, 215, 0, 255};
    sfText *text = create_text("GET ALL THREE PODS (0/3)",
    font, &gold, 30);
    button_t *button;

    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    button = create_button(create_vector(WIDTH / 10 * 8,
    HEIGHT / 20), &do_nothing, create_rect(0, 0, 0, 0), text);
    return button;
}

void update_quest(scene_t *scene, int pods_collected)
{
    char *text = malloc(sizeof(char) *
        (my_strlen("GET ALL THREE PODS (0/3)") + 1));
    char *pods_str = int_to_str(pods_collected);

    if (pods_collected >= 3)
        my_strcpy(text, "      \t\t\tGO FREE WASHY !");
    else {
        my_strcpy(text, "GET ALL THREE PODS (");
        my_strcat(text, pods_str);
        my_strcat(text, "/3)");
    }
    sfText_setString(scene->buttons[0]->text, text);
    free(text);
    free(pods_str);
}
