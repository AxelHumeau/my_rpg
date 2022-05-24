/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init enemy
*/

#include "my_rpg.h"

static char *custom_read_line(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    int end_of_file = 0;

    end_of_file = getline(&line, &len, file);
    if (end_of_file == - 1) {
        free(line);
        return NULL;
    }
    if (line[0] == '#' || line[0] == '\n') {
        free(line);
        return custom_read_line(file);
    }
    return line;
}

static char *get_next_line(game_t *game, char *line, FILE *config_file)
{
    line = custom_read_line(config_file);
    if (line == NULL) {
        game->is_invalid = true;
        return (line = my_strdup("0,:0,:0,:0"));
    }
    return (line);
}

static char *file_enemy_info2(game_t *game, char *line, FILE *config_file,
int i)
{
    char **tmp  = my_str_separator(line, ":");

    game->nmi_inf[i]->size.x = my_atof(tmp[0]);
    if (array_length(tmp) == 2)
        game->nmi_inf[i]->size.y = my_atof(tmp[1]);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->path_sprite = my_strdup(line);
    game->nmi_inf[i]->path_sprite[my_strlen(line) - 1] = '\0';
    line = get_next_line(game, line, config_file);
    tmp = my_str_separator(line, ":");
    if (array_length(tmp) == 4)
        game->nmi_inf[i]->rect = create_rect(my_getnbr(tmp[0]),
        my_getnbr(tmp[1]), my_getnbr(tmp[2]), my_getnbr(tmp[3]));
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->animation = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->reach = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->xp = my_getnbr(line);
    return (line);
}

static char *file_enemy_info(game_t *game, char *line, FILE *config_file,
int i)
{
    char **tmp;

    game->nmi_inf[i]->cac = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->health = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    tmp = my_str_separator(line, ":");
    game->nmi_inf[i]->speed.x = my_atof(tmp[0]);
    if (array_length(tmp) == 2)
        game->nmi_inf[i]->speed.y = my_atof(tmp[1]);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->damage = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->attack_speed = my_atof(line);
    line = get_next_line(game, line, config_file);
    game->nmi_inf[i]->type = my_getnbr(line);
    line = get_next_line(game, line, config_file);
    return (file_enemy_info2(game, line, config_file, i));
}

void init_enemy(game_t *game)
{
    FILE *config_file = fopen(".config/enemy.config", "r");
    char *line = NULL;
    int i = 0;

    if (config_file == NULL) {
        sfRenderWindow_close(game->window);
        return;
    }
    line = read_line(config_file);
    while (line != NULL) {
        game->nmi_inf[i] = malloc(sizeof(enemies_info_t));
        line = file_enemy_info(game, line, config_file, i);
        if (game->is_invalid)
            break;
        line = read_line(config_file);
        i++;
    }
    free(line);
    game->nmi_inf[i] = NULL;
}
