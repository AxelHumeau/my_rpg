/*
** EPITECH PROJECT, 2021
** printf
** File description:
** my_putnbr_base_char_and_unsigned
*/

int my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base_unsigned(unsigned int nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        my_putchar(base[nb]);
        return (0);
    } else {
        my_putnbr_base_unsigned(nb / basenb, base);
        my_putchar(base[nb % basenb]);
        return (0);
    }
}

int my_putnbr_base_long_unsigned(unsigned long nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        my_putchar(base[nb]);
        return (0);
    } else {
        my_putnbr_base_long_unsigned(nb / basenb, base);
        my_putchar(base[nb % basenb]);
        return (0);
    }
}

int my_putnbr_base_long_long_unsigned(unsigned long long nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        my_putchar(base[nb]);
        return (0);
    } else {
        my_putnbr_base_long_long_unsigned(nb / basenb, base);
        my_putchar(base[nb % basenb]);
        return (0);
    }
}

int my_putnbr_base_short_unsigned(unsigned short nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        my_putchar(base[nb]);
        return (0);
    } else {
        my_putnbr_base_short_unsigned(nb / basenb, base);
        my_putchar(base[nb % basenb]);
        return (0);
    }
}

int my_putnbr_base_char_unsigned(unsigned char nb, char const *base)
{
    int basenb = my_strlen(base);

    if ((nb % basenb) == nb){
        my_putchar(base[nb]);
        return (0);
    } else {
        my_putnbr_base_char_unsigned(nb / basenb, base);
        my_putchar(base[nb % basenb]);
        return (0);
    }
}
