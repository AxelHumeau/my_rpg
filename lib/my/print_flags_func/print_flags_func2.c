/*
** EPITECH PROJECT, 2021
** Git folders
** File description:
** print_flags_func2
*/

#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"

void my_printf_flag_upper_s(va_list ap, char const *format, int i)
{
    char *str = va_arg(ap, char *);
    tformat_t tests = detect_imcompatible_flag(format, i);
    int nb_to_print = my_strlen_upper_s(str);

    my_putstr_upper_s_flag(str);
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_b(va_list ap, char const *format, int i)
{
    int nb = va_arg(ap, int);
    int nb_to_print = my_nbr_len_base(nb, 2);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash(format, i, &nb_to_print, nb);
    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base(nb, "01");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_o(va_list ap, char const *format, int i)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 8);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_unsigned(nb, "01234567");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_u(va_list ap, char const *format, int i)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_unsigned(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_x(va_list ap, char const *format, int i)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_unsigned(nb, "0123456789abcdef");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
