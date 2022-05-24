/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** display str
*/

#include <wchar.h>
#include "printf.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

void my_putstr_upper_s_flag2(char const *str, int i)
{
    if (str[i] < 32)
        my_putchar('0');
    if (str[i] < 8)
        my_putchar('0');
}

void my_putstr_upper_s_flag(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr_upper_s_flag2(str, i);
            my_putnbr_base((int)str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
}

int my_putstr_wchar_t(wchar_t const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar_wchar_t(str[i]);
        i = i + 1;
    }
    return (0);
}
