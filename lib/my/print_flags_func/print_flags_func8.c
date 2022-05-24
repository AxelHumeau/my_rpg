/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print_flags_func8
*/

#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"
#include <wchar.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

void my_printf_flag_ju(va_list ap, char const *format, int i)
{
    uintmax_t nb = va_arg(ap, uintmax_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_uintmax_t(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_jx(va_list ap, char const *format, int i)
{
    uintmax_t nb = va_arg(ap, uintmax_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_uintmax_t(nb, "0123456789abcdef");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_j_upper_x(va_list ap, char const *format, int i)
{
    uintmax_t nb = va_arg(ap, uintmax_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_uintmax_t(nb, "0123456789ABCDEF");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_zdi(va_list ap, char const *format, int i)
{
    ssize_t nb = va_arg(ap, ssize_t);
    int nb_to_print = my_nbr_len_base(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_ssize_t(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_zo(va_list ap, char const *format, int i)
{
    size_t nb = va_arg(ap, size_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 8);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_size_t(nb, "01234567");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
