/*
** EPITECH PROJECT, 2021
** Pool day 7
** File description:
** concatenate two strings
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
