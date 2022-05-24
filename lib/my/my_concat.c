/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_concat
*/

#include <stdlib.h>
#include "my.h"

char *my_concat(char *str1, char *str2)
{
    char *out = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i;

    for (i = 0; str1[i] != '\0'; i++)
        out[i] = str1[i];
    for (; str2[i - my_strlen(str1)] != '\0'; i++)
        out[i] = str2[i - my_strlen(str1)];
    out[i] = '\0';
    return out;
}
