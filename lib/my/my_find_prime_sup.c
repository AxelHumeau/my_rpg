/*
** EPITECH PROJECT, 2021
** Pool day 5
** File description:
** find superior or equal prime number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (2);
    while (!(my_is_prime(nb))){
        nb = nb + 1;
    }
    return (nb);
}
