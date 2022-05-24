/*
** EPITECH PROJECT, 2021
** Pool day 3
** File description:
** my putchar
*/

#include <unistd.h>
#include <wchar.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_wint_t(wint_t c)
{
    write(1, &c, 1);
}

void my_putchar_wchar_t(wchar_t c)
{
    write(1, &c, 1);
}
