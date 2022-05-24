/*
** EPITECH PROJECT, 2021
** Pool day 4
** File description:
** display str
*/

#include <unistd.h>

int my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
