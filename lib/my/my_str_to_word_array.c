/*
** EPITECH PROJECT, 2021
** Pool day 8
** File description:
** task04
*/

#include <stdlib.h>

int is_btwn(char c1, char c2, char c3);
int my_strlen(char const *str);
char *my_strdup(char const *src);

int is_alphanum(char c1)
{
    if (is_btwn(c1, 'a', 'z'))
        return (1);
    if (is_btwn(c1, 'A', 'Z'))
        return (1);
    if (is_btwn(c1, '0', '9'))
        return (1);
    return (0);
}

void fill_str_temp(char const *str, char *str_temp, int *j)
{
    int i = 0;

    for (; is_alphanum(str[*j]); *j += 1, i++){
        str_temp[i] = str[*j];
    }
    str_temp[i] = '\0';
    *j += 1;
    while (str_temp[0] == '\0'){
        free(str_temp);
        str_temp = malloc(sizeof(char) * (my_strlen(str) + 1));
        fill_str_temp(str, str_temp, j);
    }
}

void fill_word_array(char const *str, char *str_temp, char **word_array, int i)
{
    if (my_strlen(str) == 0){
        word_array[0] = "";
        word_array[1] = NULL;
    } else {
        word_array[i] = my_strdup(str_temp);
        word_array[i][my_strlen(str_temp)] = '\0';
    }
}

void find_word_nbr(char const *str, int *nb_word, int i)
{
    if (!(is_alphanum(str[i]))){
        if (is_alphanum(str[i + 1]))
            *nb_word += 1;
    }
    if (is_alphanum(str[i]) && i == 0)
        *nb_word += 1;
}

char **my_str_to_word_array(char const *str)
{
    char **word_array;
    int nb_word = 0;
    int i = 0;
    char *str_temp;
    int j = 0;

    for (; str[i] != '\0'; i++){
        find_word_nbr(str, &nb_word, i);
    }
    word_array = malloc(sizeof(char *) * (nb_word + 1));
    word_array[nb_word] = NULL;
    for (i = 0; i < nb_word; i++){
        str_temp = malloc(sizeof(char) * (my_strlen(str) + 1));
        fill_str_temp(str, str_temp, &j);
        fill_word_array(str, str_temp, word_array, i);
        free(str_temp);
    }
    return (word_array);
}
