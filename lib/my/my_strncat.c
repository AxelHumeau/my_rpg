/*
** EPITECH PROJECT, 2021
** Pool day 7
** File description:
** concatenate two strings with n character
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
