/*
** EPITECH PROJECT, 2021
** Pool day 5
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
    int div = 1;

    if (nb == 1)
        return (1);
    if (nb <= 0)
        return (0);
    while ((nb / div != div) && (div < (nb / 2))){
        div = div + 1;
    }
    if ((nb / div == div) && (nb % div == 0)){
        return (div);
    } else {
        return (0);
    }
}
