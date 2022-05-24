/*
** EPITECH PROJECT, 2021
** printf
** File description:
** my_putnbr_base_other_type
*/

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

int my_putchar(char c);
int my_strlen(char const *str);
int my_abs(int n);

int my_putnbr_base_intmax_t(intmax_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_intmax_t(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_uintmax_t(uintmax_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_uintmax_t(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_size_t(size_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_size_t(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_ssize_t(ssize_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_ssize_t(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}

int my_putnbr_base_ptrdiff_t(ptrdiff_t nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        if (nb < 0){
            my_putchar('-');
        }
        my_putchar(base[my_abs(nb)]);
        return (0);
    } else {
        my_putnbr_base_ptrdiff_t(nb / basenb, base);
        my_putchar(base[my_abs(nb % basenb)]);
        return (0);
    }
}
