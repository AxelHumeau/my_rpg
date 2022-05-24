/*
** EPITECH PROJECT, 2021
** Pool day 3
** File description:
** test if a number is negative or not
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}
