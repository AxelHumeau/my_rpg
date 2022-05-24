/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_is_in
*/

int my_is_in(char c, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return (1);
    }
    return (0);
}
