/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** init_controls
*/

#include "my_rpg.h"
#include <stdio.h>

void init_controls(game_t *game)
{
    FILE *config_file = fopen(".config/controls.config", "r");
    char *line = NULL;
    int controls[8];
    int i = 0;

    if (config_file == NULL) {
        sfRenderWindow_close(game->window);
        return;
    }
    line = read_line(config_file);
    while (line != NULL) {
        controls[i] = my_getnbr(line);
        i++;
        line = read_line(config_file);
    }
    game->controls = (controls_t) {controls[0], controls[1], controls[2],
    controls[3], controls[4], controls[5], controls[6], controls[7]};
    fclose(config_file);
}
