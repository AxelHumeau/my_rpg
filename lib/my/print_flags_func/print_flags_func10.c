/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print_flags_func10
*/

#include <stddef.h>
#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"

void my_printf_flag_tu(va_list ap, char const *format, int i)
{
    ptrdiff_t nb = va_arg(ap, ptrdiff_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_ptrdiff_t(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_tx(va_list ap, char const *format, int i)
{
    ptrdiff_t nb = va_arg(ap, ptrdiff_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_ptrdiff_t(nb, "0123456789abcdef");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_t_upper_x(va_list ap, char const *format, int i)
{
    ptrdiff_t nb = va_arg(ap, ptrdiff_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 16);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_ptrdiff_t(nb, "0123456789ABCDEF");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
