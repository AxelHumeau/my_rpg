/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** info_tab_config
*/

#pragma once

#include "my_rpg.h"

typedef int (*get_info_t)(sfIntRect *rect, char *line, info_tab_t *tab);

int get_pos(sfIntRect *rect, char *line, info_tab_t *tab);
int get_openings(sfIntRect *rect, char *line, info_tab_t *tab);
int get_type(sfIntRect *rect, char *line, info_tab_t *tab);
int get_enemies(sfIntRect *rect, char *line, info_tab_t *tab);

const get_info_t INFO_FUNC[4] = {&get_pos, &get_openings,
                                &get_type, &get_enemies};
