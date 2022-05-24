/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_callback
*/

#include "my_rpg.h"

void quit_game(game_t *game, button_t *button)
{
    game->is_paused = 0;
    sfRenderWindow_close(game->window);
}

void do_nothing(game_t *game, button_t *button)
{
    return;
}

void return_to_menu(game_t *game, button_t *button)
{
    sfMusic_stop(game->scenes[game->current_scene]->music);
    game->current_scene = START_MENU;
    game->is_paused = 0;
    sfMusic_play(game->scenes[game->current_scene]->music);
}

void next_scene(game_t *game, button_t *button)
{
    sfMusic_stop(game->scenes[game->current_scene]->music);
    game->current_scene++;
    sfMusic_play(game->scenes[game->current_scene]->music);
}
