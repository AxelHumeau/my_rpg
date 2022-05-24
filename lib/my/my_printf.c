/*
** EPITECH PROJECT, 2021
** Git folders
** File description:
** my_printf
*/

#include <stdarg.h>
#include "struct_format.h"
#include "printf.h"
#include "printf_flags.h"

void find_format(char const *format, int *i)
{
    if (format[*i + 1] == '#') {
        *i += 1;
        find_format(format, i);
    }
    if (format[*i + 1] >= '0' && format[*i + 1] <= '9') {
        *i += 1;
        find_format(format, i);
    }
    if (format[*i + 1] == '-') {
        *i += 1;
        find_format(format, i);
    }
    if (format[*i + 1] == ' ') {
        *i += 1;
        find_format(format, i);
    }
    if (format[*i + 1] == '+') {
        *i += 1;
        find_format(format, i);
    }
}

int find_flags_with_multiple_letters(char const *format, int *i, int j)
{
    if (my_strlen(FLAGS[j].flag) == 3 && format[*i + 1] == FLAGS[j].flag[0] &&
    format[*i + 2] == FLAGS[j].flag[1] && format[*i + 3] == FLAGS[j].flag[2]) {
        *i += 3;
        return (j);
    } else if (my_strlen(FLAGS[j].flag) == 2 &&
    format[*i + 1] == FLAGS[j].flag[0] && format[*i + 2] == FLAGS[j].flag[1]) {
        *i += 2;
        return (j);
    }
    return (-1);
}

p_flag find_flag(char const *format, int *i)
{
    int index;

    for (int j = 0; FLAGS[j].flag != 0; j++) {
        index = find_flags_with_multiple_letters(format, i, j);
        if (index != -1) {
            return (FLAGS[index].function);
        }
        if (format[*i + 1] == FLAGS[j].flag[0] && FLAGS[j].flag[0] != 'l' &&
        FLAGS[j].flag[0] != 'h' && FLAGS[j].flag[0] != 'j' &&
        FLAGS[j].flag[0] != 'z' && FLAGS[j].flag[0] != 't') {
            *i += 1;
            return (FLAGS[j].function);
        }
    }
    return (FLAGS[PERCENT].function);
}

int my_printf(char const *format, ...)
{
    va_list ap;
    int i = 0;
    int i_percent = 0;
    p_flag display;

    va_start(ap, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i_percent = i + 1;
            find_format(format, &i);
            display = find_flag(format, &i);
            display(ap, format, i_percent);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return (0);
}
