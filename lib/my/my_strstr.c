/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** strstr
*/

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int j;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        for (j = i; (str[j] == to_find[j - i]) && (str[j] != '\0'); j++){
        }
        if ((j - i) == my_strlen(to_find))
            return &str[i];
    }
    return ('\0');
}
