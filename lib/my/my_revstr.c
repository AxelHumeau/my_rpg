/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** reverse a str
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int temp;

    while (i < (len - i - 1)) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i = i + 1;
    }
    return str;
}
