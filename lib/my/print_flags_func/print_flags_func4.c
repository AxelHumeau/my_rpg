/*
** EPITECH PROJECT, 2021
** Git folders
** File description:
** print_flags_func3
*/

#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"

void my_printf_flag_ldi(va_list ap, char const *format, int i)
{
    long nb = va_arg(ap, long);
    int nb_to_print = my_nbr_len_base(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_long(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_llo(va_list ap, char const *format, int i)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 8);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_long_long_unsigned(nb, "01234567");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_llu(va_list ap, char const *format, int i)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_long_long_unsigned(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_llx(va_list ap, char const *format, int i)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_long_long_unsigned(nb, "0123456789abcdef");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_ll_upper_x(va_list ap, char const *format, int i)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_long_long_unsigned(nb, "0123456789ABCDEF");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
