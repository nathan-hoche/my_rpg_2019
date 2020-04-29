/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/
#include "my.h"

int select_number(char const *str, int sign, int i, int result)
{
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            result = result * 10;
            result = result + str[i] - 48;
            i++;
        } else {
            result = result * sign;
            return (result);
        }
    }
    result = result * sign;
    return (result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            sign = sign * -1;
        i++;
    }
    select_number(str, sign, i, result);
}