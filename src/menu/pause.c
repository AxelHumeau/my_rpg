/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause
*/

#include "my_rpg.h"

void pause_b(game_t *game, button_t *button)
{
    game->is_paused = 1;
    sfMusic_pause(game->scenes[game->current_scene]->music);
}

void resume(game_t *game, button_t *button)
{
    game->is_paused = 0;
    sfMusic_play(game->scenes[game->current_scene]->music);
}

void draw_object(game_t *game)
{
    scene_t *scene = game->scenes[game->current_scene];

    for (int i = 0; scene->objects[i]; i++)
        if (!scene->objects[i]->is_disabled &&
        !(scene->objects[i]->type == ITEM && scene->objects[i]->idle))
            sfRenderWindow_drawSprite(game->window,
            scene->objects[i]->sprite, NULL);
    for (int i = 0; scene->buttons[i]; i++)
        if (!scene->buttons[i]->is_disabled)
            draw_button(scene->buttons[i], game);
}

void pause_game(game_t *game)
{
    while (game->is_paused && sfRenderWindow_isOpen(game->window)) {
        draw_object(game);
        update_button(game->resume_button, game);
        update_button(game->menu_button, game);
        update_button(game->quit_button, game);
        check_events(game);
        sfRenderWindow_display(game->window);
    }
}
