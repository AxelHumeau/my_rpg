/*
** EPITECH PROJECT, 2021
** Pool day 8
** File description:
** task03
*/

int my_putstr(char *str);
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (; tab[i] != 0; i++){
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
