/*
** EPITECH PROJECT, 2022
** Solo_stumper 1
** File description:
** str_separator
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

bool produce_bool(char charac, char *separ)
{
    if (my_strlen(separ) == 0)
        return 0;
    else
        return (charac == separ[0] || produce_bool(charac, separ + 1));
}

char *fill_word(char *str, char *separators)
{
    static int begin = 0;
    int i;
    char *word;

    if (str == NULL) {
        begin = 0;
        return NULL;
    }
    for (i = begin; !produce_bool(str[i], separators) && str[i] != '\0'; i++);
    if (i == begin) {
        begin++;
        return NULL;
    }
    word = malloc(i - begin + 1);
    my_strncpy(word, str + begin, i - begin);
    begin = i + 1;
    return word;
}

void fill_uninitialised(char **words, int index, int nb_word)
{
    for (; index != nb_word; index++)
        words[index] = NULL;
    fill_word(NULL, NULL);
}

char **my_str_separator(char *str, char *separators)
{
    int nb_word = 1;
    char **words;
    char *tmp_word;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (produce_bool(str[i], separators))
            nb_word++;
    }
    words = malloc(sizeof(char *) * (nb_word + 1));
    words[nb_word] = NULL;
    for (int i = 0; i < nb_word; i++) {
        tmp_word = fill_word(str, separators);
        if (tmp_word != NULL) {
            words[index] = tmp_word;
            index++;
        }
    }
    fill_uninitialised(words, index, nb_word);
    return (words);
}
