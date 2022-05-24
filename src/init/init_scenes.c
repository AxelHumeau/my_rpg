/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** init_scenes
*/

#include "my_rpg.h"

static int find_nb_type(FILE *file)
{
    char *buffer = NULL;
    int nb_type = 0;

    if (file == NULL)
        return -1;
    buffer = read_line(file);
    if (buffer == NULL) {
        free(buffer);
        return -1;
    }
    nb_type = my_getnbr(buffer);
    free(buffer);
    return nb_type;
}

void init_scenes(scene_t *scene, game_t *game)
{
    FILE *config_file = fopen(".config/scenes.config", "r");
    int nb_type = find_nb_type(config_file);

    if (nb_type <= 0) {
        if (config_file != NULL)
            fclose(config_file);
        game->is_invalid = true;
        return;
    }
    if (read_tab_rect_info(nb_type, config_file, scene))
        game->is_invalid = true;
    fclose(config_file);
}
