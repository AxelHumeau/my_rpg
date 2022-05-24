/*
** EPITECH PROJECT, 2021
** Pool day 9
** File description:
** contains prototypes of the functions in libmy.a
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

int is_btwn(int c1, int c2, int c3);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *desc, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
int my_abs(int n);
int is_between(int nb, int v1, int v2);
void find_nb_beginning(char const *str, int *p_or_n, int *i1, int *i2);
void find_nb_end(char const *str, int *i2);
int calc_nb(char const *str, int *i1, int i2, long long *nb);
void min_search(int *array, int *min, int b, int size);
void test_letter(char *str, int i);
void test_letter_d(char *str, int i);
int is_alphanum(char c1);
void fill_str_temp(char const *str, char *str_temp, int *j);
void fill_word_array(char const *str, char *str_temp,
char **word_array, int i);
void find_word_nbr(char const *str, int *nb_word, int i);
int my_show_word_array(char * const *tab);
int my_puterror(char const *str);
int my_printf(char const *format, ...);
int my_is_in(char c, char const *str);
char *int_to_str(int nb);
int my_nbr_len_base(long long nbr, int base);
char **my_str_separator(char *str, char *separtors);
int array_length(char **array);
int is_btwn_f(float c1, float c2, float c3);
float my_fabs(float n);
char *my_concat(char *str1, char *str2);
void free_word_array(char **word_array);

#endif
