/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** len
*/

#include "printf.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

void my_strlen_upper_s2(char const *str, int *c, int i)
{
    if (str[i] < 32)
        *c += 1;
    if (str[i] < 8)
        *c += 1;
}

int my_strlen_upper_s(char const *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            c++;
            my_strlen_upper_s2(str, &c, i);
            c += my_nbr_len_base((int)str[i], 8);
        } else
            c++;
    }
    return (c);
}

int my_strlen_wchar_t(wchar_t const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
