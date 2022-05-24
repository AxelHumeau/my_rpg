/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** task 08
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] <= 122) && (str[i] >= 97))
            str[i] -= 32;
    }
    return (str);
}
