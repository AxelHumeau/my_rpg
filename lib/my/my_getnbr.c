/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** task5
*/

#include <stddef.h>

void find_nb_beginning(char const *str, int *p_or_n, int *i1, int *i2)
{
    while ((str[*i1] == '+') || (str[*i1] == '-')) {
        if (str[*i1] == '-')
            *p_or_n = *p_or_n * -1;
        *i1 = *i1 + 1;
    }
    *i2 = *i1;
}

void find_nb_end(char const *str, int *i2)
{
    while ((str[*i2] >= 48) && (str[*i2] <= 57)) {
        *i2 = *i2 + 1;
    }
}

int calc_nb(char const *str, int *i1, int i2, long long *nb)
{
    int len = i2 - *i1;
    int ten_pow = len - 1;

    while (ten_pow >= 0){
        *nb = *nb * 10;
        *nb = *nb + (str[*i1] - 48);
        if (*nb > 2147483648)
            return (0);
        ten_pow = ten_pow - 1;
        *i1 = *i1 + 1;
    }
    return (1);
}

int my_getnbr(char const *str)
{
    int i1 = 0;
    int i2;
    int p_or_n = 1;
    long long nb = 0;
    int nb_int = 0;
    int test;

    if (str == NULL)
        return (0);
    find_nb_beginning(str, &p_or_n, &i1, &i2);
    find_nb_end(str, &i2);
    test = calc_nb(str, &i1, i2, &nb);
    nb = nb * p_or_n;
    if (test) {
        nb_int = (int) nb;
        return (nb_int);
    }
    return (0);
}
