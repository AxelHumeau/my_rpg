/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_atof
*/

#include "my_rpg.h"

float my_atof(char *str)
{
    char **tmp;
    float result = 0;
    float buffer = 0;
    int exept = 0;

    if (str == NULL)
        return (0);
    tmp = my_str_separator(str, ",.");
    result = my_getnbr(tmp[0]);
    if (tmp[1] != NULL) {
        buffer = my_getnbr(tmp[1]);
        if (my_strlen(tmp[1]) > 1)
            exept = 1;
        for (int i = 0; i + exept < my_strlen(tmp[1]); i++)
            buffer /= 10;
    }
    result += buffer;
    return (result);
}
