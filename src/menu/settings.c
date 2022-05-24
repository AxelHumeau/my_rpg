/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** settings
*/

#include "my_rpg.h"

void display_settings(game_t *game, button_t *button)
{
    CURRENT_SCENE->buttons[0]->is_disabled = 1;
    CURRENT_SCENE->buttons[1]->is_disabled = 1;
    CURRENT_SCENE->buttons[2]->is_disabled = 1;
    CURRENT_SCENE->buttons[3]->is_disabled = 1;
    CURRENT_SCENE->buttons[4]->is_disabled = 0;
    CURRENT_SCENE->buttons[5]->is_disabled = 0;
    CURRENT_SCENE->buttons[6]->is_disabled = 0;
    CURRENT_SCENE->buttons[7]->is_disabled = 0;
    CURRENT_SCENE->buttons[8]->is_disabled = 0;
}

static void apply_volume(game_t *game)
{
    char *volume_str;
    char *new_percent_text;

    for (int i = 0; i < NB_SCENES; i++)
        sfMusic_setVolume(game->scenes[i]->music, game->volume);
    for (int i = 0; i < PROJ_NB; i++)
        sfMusic_setVolume(game->proj[i]->song, game->volume);
    volume_str = int_to_str(game->volume);
    new_percent_text = my_concat(volume_str, "%");
    sfText_setString(CURRENT_SCENE->buttons[7]->text, new_percent_text);
    free(volume_str);
    free(new_percent_text);
}

void increase_volume(game_t *game, button_t *button)
{
    if (game->volume < 100)
        game->volume += 10;
    apply_volume(game);
}

void decrease_volume(game_t *game, button_t *button)
{
    if (game->volume > 0)
        game->volume -= 10;
    apply_volume(game);
}
