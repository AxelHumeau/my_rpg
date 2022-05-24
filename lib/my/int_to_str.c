/*
** EPITECH PROJECT, 2021
** Pool day 3
** File description:
** display number
*/

#include <stdlib.h>
#include "my.h"

int int_transform(int nb, char *str, int i)
{
    if ((nb % 10) == nb) {
        str[i] = nb + 48;
        return (0);
    } else {
        str[i] = nb % 10 + 48;
        int_transform(nb / 10, str, i - 1);
        return (0);
    }
}

char *int_to_str(int nb)
{
    int len = my_nbr_len_base(nb, 10);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        str[i] = '0';
    int_transform(my_abs(nb), str, len - 1);
    if (nb < 0)
        str[0] = '-';
    str[len] = '\0';
    return (str);
}
