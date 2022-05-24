/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** read_config_file
*/

#include "info_tab_config.h"

static int read_tab_info(char *line, scene_t *scene, sfIntRect *rect, int *i)
{
    static info_tab_t *tmp;
    static int index_tab = -1;

    if (line[0] == '\n' || *i == 4) {
        *i = 0;
        index_tab++;
        tmp = malloc(sizeof(info_tab_t));
    } else {
        if (INFO_FUNC[*i](rect, line, tmp))
            return 1;
        scene->tab[index_tab] = tmp;
        (*i)++;
    }
    free(line);
    return 0;
}

int read_file_config(FILE *file, scene_t *scene,
sfIntRect *rect, char *line)
{
    int i = -1;
    int j;

    scene->nb_tabs = my_getnbr(line);
    if (scene->nb_tabs <= 0)
        return 1;
    scene->tab = malloc(sizeof(info_tab_t *) * scene->nb_tabs);
    line = read_line(file);
    if (line[0] != '\n')
        return 1;
    for (j = 0; line != NULL && j < scene->nb_tabs; j += i == 4,
    line = read_line(file)) {
        if (line[0] == '\n' && is_btwn(i, 0, 3))
            continue;
        if (read_tab_info(line, scene, rect, &i))
            return 1;
    }
    if (j != scene->nb_tabs)
        return 1;
    return 0;
}

static char *find_next_comma(char *string)
{
    while (string[0] != ',' && string[0] != '\n')
        string++;
    string++;
    return string;
}

int read_tab_rect_info(int nb_type, FILE *config_file, scene_t *scene)
{
    char *line;
    char *tmp_line;
    int tmp[4];
    int j;
    sfIntRect rect[nb_type];

    line = read_line(config_file);
    for (j = 0; j < nb_type && line != NULL; j++) {
        tmp_line = line;
        for (int i = 0; i < 4; i++) {
            tmp[i] = my_getnbr(tmp_line);
            tmp_line = find_next_comma(tmp_line);
        }
        rect[j] = (sfIntRect) {tmp[0], tmp[1], tmp[2], tmp[3]};
        free(line);
        line = read_line(config_file);
    }
    if (j != nb_type || read_file_config(config_file, scene, rect, line))
        return 1;
    return 0;
}
