/*
** EPITECH PROJECT, 2021
** Pool day 3
** File description:
** display number
*/

int my_putchar(char c);
int my_abs(int nb);

int my_put_nbr(int nb)
{
    if ((nb % 10) == nb) {
        if (nb < 0)
            my_putchar('-');
        my_putchar(my_abs(nb) + 48);
        return (0);
    } else {
        my_put_nbr(nb / 10);
        my_putchar(my_abs(nb % 10) + 48);
        return (0);
    }
}
