/*
** EPITECH PROJECT, 2021
** Git folders
** File description:
** struct_format
*/

#pragma once
#include <stdarg.h>
#include "printf_flags.h"

#define PERCENT 7

typedef void (*p_flag)(va_list, char const *, int);

struct flags {
    char *flag;
    p_flag function;
};

struct flags const FLAGS[] = {{"c", &my_printf_flag_c},
                            {"s", &my_printf_flag_s},
                            {"d", &my_printf_flag_di},
                            {"i", &my_printf_flag_di},
                            {"p", &my_printf_flag_p},
                            {"b", &my_printf_flag_b},
                            {"S", &my_printf_flag_upper_s},
                            {"%", &my_printf_flag_percent},
                            {"o", &my_printf_flag_o},
                            {"u", &my_printf_flag_u},
                            {"x", &my_printf_flag_x},
                            {"X", &my_printf_flag_upper_x},
                            {"lo", &my_printf_flag_lo},
                            {"lu", &my_printf_flag_lu},
                            {"lx", &my_printf_flag_lx},
                            {"lX", &my_printf_flag_l_upper_x},
                            {"ld", &my_printf_flag_ldi},
                            {"li", &my_printf_flag_ldi},
                            {"llo", &my_printf_flag_llo},
                            {"llu", &my_printf_flag_llu},
                            {"llx", &my_printf_flag_llx},
                            {"llX", &my_printf_flag_ll_upper_x},
                            {"lld", &my_printf_flag_lldi},
                            {"lli", &my_printf_flag_lldi},
                            {"ho", &my_printf_flag_ho},
                            {"hu", &my_printf_flag_hu},
                            {"hx", &my_printf_flag_hx},
                            {"hX", &my_printf_flag_h_upper_x},
                            {"hd", &my_printf_flag_hdi},
                            {"hi", &my_printf_flag_hdi},
                            {"hho", &my_printf_flag_hho},
                            {"hhu", &my_printf_flag_hhu},
                            {"hhx", &my_printf_flag_hhx},
                            {"hhX", &my_printf_flag_hh_upper_x},
                            {"hhd", &my_printf_flag_hhdi},
                            {"hhi", &my_printf_flag_hhdi},
                            {"lc", &my_printf_flag_lc},
                            {"ls", &my_printf_flag_ls},
                            {"jo", &my_printf_flag_jo},
                            {"ju", &my_printf_flag_ju},
                            {"jx", &my_printf_flag_jx},
                            {"jX", &my_printf_flag_j_upper_x},
                            {"jd", &my_printf_flag_jdi},
                            {"ji", &my_printf_flag_jdi},
                            {"zo", &my_printf_flag_zo},
                            {"zu", &my_printf_flag_zu},
                            {"zx", &my_printf_flag_zx},
                            {"zX", &my_printf_flag_z_upper_x},
                            {"zd", &my_printf_flag_zdi},
                            {"zi", &my_printf_flag_zdi},
                            {"to", &my_printf_flag_to},
                            {"tu", &my_printf_flag_tu},
                            {"tx", &my_printf_flag_tx},
                            {"tX", &my_printf_flag_t_upper_x},
                            {"td", &my_printf_flag_tdi},
                            {"ti", &my_printf_flag_tdi},
                            {0, 0}};
