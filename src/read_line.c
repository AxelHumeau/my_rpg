/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** read line
*/

#include "my_rpg.h"
#include <stdio.h>

char *read_line(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    int end_of_file = 0;

    end_of_file = getline(&line, &len, file);
    if (end_of_file == - 1) {
        free(line);
        return NULL;
    }
    if (line[0] == '#') {
        free(line);
        return read_line(file);
    }
    return line;
}
