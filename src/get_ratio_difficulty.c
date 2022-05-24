/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get ratio of difficulty
*/

#include "my_rpg.h"

int get_res_with_diff(float result, float difficulty, int ratio)
{
    result = result + ((result * (difficulty * ratio)) / 100);
    return (result);
}
