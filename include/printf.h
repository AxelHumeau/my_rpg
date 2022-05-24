/*
** EPITECH PROJECT, 2021
** printf
** File description:
** printf
*/

#pragma once
#include <wchar.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define FLAG_CHAR "lhjztdiouxXcs%pbS"

typedef struct tests_format_flag {
    int test_hash;
    int test_zero;
    int test_dash;
    int test_space;
    int test_plus;
} tformat_t;

int my_strlen(char const *str);
int my_strlen_upper_s(char const *str);
int my_strlen_wchar_t(wchar_t const *str);
void my_putchar(char c);
void my_putchar_wint_t(wint_t c);
void my_putchar_wchar_t(wchar_t c);
int my_putstr(char const *str);
void my_putstr_upper_s_flag(char const *str);
int my_putstr_wchar_t(wchar_t const *str);
int my_put_nbr(int nb);
int my_putnbr_base(int nb, char const *base);
int my_putnbr_base_unsigned(int nb, char const *base);
int my_putnbr_base_long(long nb, char const *base);
int my_putnbr_base_long_unsigned(unsigned long nb, char const *base);
int my_putnbr_base_long_long(long long nb, char const *base);
int my_putnbr_base_long_long_unsigned(unsigned long long nb, char const *b);
int my_putnbr_base_short(short nb, char const *base);
int my_putnbr_base_short_unsigned(unsigned short nb, char const *base);
int my_putnbr_base_char(char nb, char const *base);
int my_putnbr_base_char_unsigned(unsigned char nb, char const *base);
int my_putnbr_base_intmax_t(intmax_t nb, char const *base);
int my_putnbr_base_uintmax_t(uintmax_t nb, char const *base);
int my_putnbr_base_size_t(size_t nb, char const *base);
int my_putnbr_base_ssize_t(ssize_t nb, char const *base);
int my_putnbr_base_ptrdiff_t(ptrdiff_t nb, char const *base);
int my_nbr_len_base(long long nbr, int base);
int my_nbr_len_base_unsigned(unsigned long long nbr, int base);
int my_getnbr(char const *str);
int my_is_in(char c, char const *str);
void find_hash(char const *format, int i, int *nb_to_print,long long nb);
void find_zero(char const *format, int i, int *nb_to_print);
void find_hash_unsigned(char const *format, int i, int *nb_to_print,
unsigned long long nb);
void find_dash(char const *format, int i, int *nb_to_print);
tformat_t detect_imcompatible_flag(char const *format, int i);
void find_space(long long man, int *nb_to_print);
void find_plus(long long man, int *nb_to_print);
