/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** strncmp
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (((i < my_strlen(s1)) || (i < my_strlen(s2))) && i < n) {
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        if (i > my_strlen(s2))
            return (s1[i]);
        if (i > my_strlen(s1))
            return (-s2[i]);
        i++;
    }
    return (0);
}
