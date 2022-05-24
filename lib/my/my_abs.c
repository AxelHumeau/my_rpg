/*
** EPITECH PROJECT, 2021
** printf
** File description:
** my_abs
*/

int my_abs(int n)
{
    if (n < 0) {
        return (n * -1);
    }
    return (n);
}

float my_fabs(float n)
{
    if (n < 0) {
        return (n * -1);
    }
    return (n);
}
