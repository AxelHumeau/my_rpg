/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** task 18
*/


#include "inttypes.h"

int my_putchar(char c);
int my_strlen(char const *str);
int my_abs(int n);

int my_putnbr_base(int nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_long(long nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_long(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_long_long(long long nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_long_long(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_short(short nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_short(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_char(int8_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_char(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}
