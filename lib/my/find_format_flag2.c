/*
** EPITECH PROJECT, 2021
** printf
** File description:
** find_format_flag
*/

#include "printf.h"

void find_space(long long man, int *nb_to_print)
{
    if (man >= 0) {
        my_putchar(' ');
        *nb_to_print += 1;
    }
}

void find_plus(long long man, int *nb_to_print)
{
    if (man >= 0) {
        my_putchar('+');
        *nb_to_print += 1;
    }
}
