/*
** EPITECH PROJECT, 2021
** printf
** File description:
** find_format_flag
*/

#include "printf.h"

void find_zero(char const *format, int i, int *nb_to_print)
{
    int pathing;

    for (; format[i] != '0'; i++);
    if (!(format[i - 1] >= '0' && format[i - 1] <= '9')) {
        pathing = my_getnbr(format + i + 1);
        for (;pathing > *nb_to_print; pathing--)
            my_putchar('0');
    }
}

void find_hash(char const *format, int i, int *nb_to_print, long long nb)
{
    int f = i;

    for (; !(my_is_in(format[f], FLAG_CHAR + 5)); f++);
    if (nb != 0) {
        if (format[f] == 'b') {
            my_putstr("0b");
            *nb_to_print += 2;
        }
    }
}

void find_hash_unsigned(char const *format, int i, int *nb_to_print,
unsigned long long nb)
{
    int f = i;

    for (; !(my_is_in(format[f], FLAG_CHAR + 5)); f++);
    if (nb != 0) {
        if (format[f] == 'o') {
            my_putchar('0');
            *nb_to_print += 1;
        }
        if (format[f] == 'x') {
            my_putstr("0x");
            *nb_to_print += 2;
        }
        if (format[f] == 'X') {
            my_putstr("0X");
            *nb_to_print += 2;
        }
    }
}

void find_dash(char const *format, int i, int *nb_to_print)
{
    int pathing;

    for (; format[i] != '-'; i++);
    pathing = my_getnbr(format + i + 1);
    for (;pathing > *nb_to_print; pathing--)
        my_putchar(' ');
}

tformat_t detect_imcompatible_flag(char const *format, int i)
{
    tformat_t tests = {0, 0, 0, 0, 0};

    for (; !(my_is_in(format[i], FLAG_CHAR)); i++) {
        if (format[i] == '-') {
            tests.test_zero = -1;
            tests.test_dash = 1;
        }
        if (format[i] == '+') {
            tests.test_space = -1;
            tests.test_plus = 1;
        }
        if (format[i] == '0' && tests.test_zero != -1)
            tests.test_zero = 1;
        if (format[i] == ' ' && tests.test_space != -1)
            tests.test_space = 1;
        if (format[i] == '#')
            tests.test_hash = 1;
    }
    return (tests);
}
