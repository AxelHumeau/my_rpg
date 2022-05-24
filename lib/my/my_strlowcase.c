/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** task 9
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++){
        if ((str[i] <= 90) && (str[i] >= 65))
            str[i] += 32;
    }
    return (str);
}
