/*
** EPITECH PROJECT, 2021
** Pool day 5
** File description:
** is prime ?
*/

int my_is_prime(int nb)
{
    int div = 2;

    if (nb <= 1)
        return (0);
    while ((div < nb) && (nb % div != 0)){
        div = div + 1;
    }
    if ((nb % div == 0) && (div != nb))
        return (0);
    return (1);
}
