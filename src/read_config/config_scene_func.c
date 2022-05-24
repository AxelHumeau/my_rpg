/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** config scene_func
*/

#include "my_rpg.h"

int get_pos(sfIntRect *rect, char *line, info_tab_t *tab)
{
    char **pos_str = my_str_separator(line, ":\n");

    if (array_length(pos_str) != 2) {
        free_word_array(pos_str);
        return 1;
    }
    tab->pos.x = my_getnbr(pos_str[0]);
    tab->pos.y = my_getnbr(pos_str[1]);
    free_word_array(pos_str);
    return 0;
}

int get_openings(sfIntRect *rect, char *line, info_tab_t *tab)
{
    char **op_str = my_str_separator(line, ":\n");

    if (array_length(op_str) != 4) {
        free_word_array(op_str);
        return 1;
    }
    tab->op_left = my_getnbr(op_str[0]);
    tab->op_up = my_getnbr(op_str[1]);
    tab->op_right = my_getnbr(op_str[2]);
    tab->op_down = my_getnbr(op_str[3]);
    free_word_array(op_str);
    return 0;
}

int get_type(sfIntRect *rect, char *line, info_tab_t *tab)
{
    char **tmp = my_str_separator(line, ":;");

    if (array_length(tmp) != 2) {
        free_word_array(tmp);
        return 1;
    }
    tab->type = my_getnbr(tmp[0]);
    tab->rect = rect[tab->type];
    tab->difficulty = my_atof(tmp[1]);
    free_word_array(tmp);
    return 0;
}

static int get_enemies_info(info_tab_t *tab, char **enemies_str)
{
    char **tmp_pos_str;
    int j = 0;

    tab->type_enemies = malloc(sizeof(int) * tab->nb_enemies);
    for (int i = 1; i <= tab->nb_enemies; i++, j++) {
        tmp_pos_str = my_str_separator(enemies_str[i], ",");
        tab->type_enemies[j] = my_getnbr(tmp_pos_str[0]);
        free_word_array(tmp_pos_str);
    }
    free_word_array(enemies_str);
    return 0;
}

int get_enemies(sfIntRect *rect, char *line, info_tab_t *tab)
{
    char **enemies_str = my_str_separator(line, ":\n");

    if (enemies_str[0] == NULL) {
        free_word_array(enemies_str);
        return 1;
    }
    tab->nb_enemies = my_getnbr(enemies_str[0]);
    if (tab->nb_enemies == 0) {
        tab->enemies_pos = NULL;
        free_word_array(enemies_str);
        return 0;
    }
    if (array_length(enemies_str) != tab->nb_enemies + 1) {
        free_word_array(enemies_str);
        return 1;
    }
    if (get_enemies_info(tab, enemies_str))
        return 1;
    return 0;
}
