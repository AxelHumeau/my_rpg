/*
** EPITECH PROJECT, 2021
** Git folders
** File description:
** print_flags_func
*/

#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"

void my_printf_flag_c(va_list ap, char const *format, int i)
{
    tformat_t tests = detect_imcompatible_flag(format, i);
    int nb_to_print = 1;

    my_putchar(va_arg(ap, int));
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_s(va_list ap, char const *format, int i)
{
    char *str = va_arg(ap, char *);
    tformat_t tests = detect_imcompatible_flag(format, i);
    int nb_to_print = my_strlen(str);

    my_putstr(str);
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_di(va_list ap, char const *format, int i)
{
    int nb = va_arg(ap, int);
    int nb_to_print = my_nbr_len_base(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_put_nbr(nb);
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_percent(va_list ap, char const *format, int i)
{
    my_putchar('%');
}

void my_printf_flag_p(va_list ap, char const *format, int i)
{
    long pointer = (long)va_arg(ap, void *);
    int nb_to_print = my_nbr_len_base(pointer, 16) + 2;
    tformat_t tests = detect_imcompatible_flag(format, i);

    my_putstr("0x");
    my_putnbr_base_long(pointer, "0123456789abcdef");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
