/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game_loop
*/

#include "my_rpg.h"

void check_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed) {
            create_inventory(game);
        }
    }
}

void check_escape(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->controls.pause))
        pause_b(game, game->pause_button);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        refresh_scene(game);
        if (game->current_scene) {
            update_button(game->pause_button, game);
            projectile_handle(game);
            inventory_handle(game);
            check_escape(game);
        }
        pause_game(game);
        check_events(game);
        sfRenderWindow_display(game->window);
    }
}
