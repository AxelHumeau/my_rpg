/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** task 15
*/

int is_btwn(char c1, char c2, char c3);

int my_str_isupper(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (!(is_btwn(str[i], 'A', 'Z')))
            return (0);
    }
    return (1);
}
