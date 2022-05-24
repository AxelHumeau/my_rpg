/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** free_word_array
*/

#include "my.h"
#include <stdlib.h>

void free_word_array(char **word_array)
{
    for (int i = 0; word_array[i] != NULL; free(word_array[i]), i++);
    free(word_array);
}
