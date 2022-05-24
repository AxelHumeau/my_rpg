/*
** EPITECH PROJECT, 2021
** printf
** File description:
** print_flags_func7
*/

#include <stdarg.h>
#include "printf.h"
#include "printf_flags.h"
#include <wchar.h>
#include <stdint.h>
#include <stddef.h>

void my_printf_flag_hhdi(va_list ap, char const *format, int i)
{
    char nb = va_arg(ap, int);
    int nb_to_print = my_nbr_len_base(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_char(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_lc(va_list ap, char const *format, int i)
{
    tformat_t tests = detect_imcompatible_flag(format, i);
    int nb_to_print = 1;

    my_putchar_wint_t(va_arg(ap, wint_t));
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_ls(va_list ap, char const *format, int i)
{
    wchar_t *wstr = va_arg(ap, wchar_t *);
    tformat_t tests = detect_imcompatible_flag(format, i);
    int nb_to_print = my_strlen_wchar_t(wstr);

    my_putstr_wchar_t(wstr);
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_jdi(va_list ap, char const *format, int i)
{
    intmax_t nb = va_arg(ap, intmax_t);
    int nb_to_print = my_nbr_len_base(nb, 10);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_space > 0)
        find_space(nb, &nb_to_print);
    if (tests.test_plus)
        find_plus(nb, &nb_to_print);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_intmax_t(nb, "0123456789");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}

void my_printf_flag_jo(va_list ap, char const *format, int i)
{
    uintmax_t nb = va_arg(ap, uintmax_t);
    int nb_to_print = my_nbr_len_base_unsigned(nb, 8);
    tformat_t tests = detect_imcompatible_flag(format, i);

    if (tests.test_hash)
        find_hash_unsigned(format, i, &nb_to_print, nb);
    if (tests.test_zero > 0)
        find_zero(format, i, &nb_to_print);
    my_putnbr_base_uintmax_t(nb, "01234567");
    if (tests.test_dash)
        find_dash(format, i, &nb_to_print);
}
