/*
** EPITECH PROJECT, 2021
** Pool day 6
** File description:
** task 10
*/

int is_btwn(char c1, char c2, char c3);

void test_letter(char *str, int i)
{
    if ((i == 0) || (!(is_btwn(str[i - 1], 'A', 'Z')))){
        if ((i == 0) || (!(is_btwn(str[i - 1], 'a', 'z'))))
            str[i] -= 32;
    }
}

void test_letter_d(char *str, int i)
{
    if ((i != 0) && (!(str[i - 1] == ' ')))
        str[i] += 32;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++){
        if (is_btwn(str[i], 'a', 'z')){
            test_letter(str, i);
        } else if (is_btwn(str[i], 'A', 'Z')){
            test_letter_d(str, i);
        }
    }
    return (str);
}
