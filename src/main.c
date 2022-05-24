/*
** EPITECH PROJECT, 2022
** Graphical Programing
** File description:
** main
*/

#include "my_rpg.h"
#include "my.h"

int main(int argc, char **argv)
{
    game_t *game;
    int to_return = 84;

    game = create_game("PLAYER");
    if (!game->is_invalid) {
        game_loop(game);
        to_return = 0;
        destroy_game(game);
    }
    return to_return;
}
