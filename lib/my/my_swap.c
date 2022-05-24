/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int *temp;

    *temp = *a;
    *a = *b;
    *b = *temp;
}
