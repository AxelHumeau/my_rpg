/*
** EPITECH PROJECT, 2021
** printf
** File description:
** my_nbr_len
*/

int my_nbr_len_base(long long nbr, int base)
{
    int len = 1;

    if (nbr < 0)
        len++;
    while (nbr / base != 0) {
        len++;
        nbr /= base;
    }
    return (len);
}

int my_nbr_len_base_unsigned(unsigned long long nbr, int base)
{
    int len = 1;

    while (nbr / base != 0) {
        len++;
        nbr /= base;
    }
    return (len);
}
