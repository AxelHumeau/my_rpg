/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** copy n character in a str
*/

int my_strlen(char const *str);

char *my_strncpy(char *desc, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++){
        desc[i] = src[i];
    }
    desc[i] = '\0';
    return (desc);
}
