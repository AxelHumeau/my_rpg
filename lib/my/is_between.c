/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** is between (not a task)
*/

int is_btwn(int c1, int c2, int c3)
{
    if ((c1 <= c3) && (c1 >= c2))
        return (1);
    return (0);
}

int is_btwn_f(float c1, float c2, float c3)
{
    if ((c1 <= c3) && (c1 >= c2))
        return (1);
    return (0);
}
