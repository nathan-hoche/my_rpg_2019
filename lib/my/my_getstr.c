/*
** EPITECH PROJECT, 2020
** SHOW_NUMBER
** File description:
** covnert int to char
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int sizer(int nb)
{
    int count = 0;
    int rest = nb;

    if (nb == 0) {
        count = 1;
        return (count);
    }
    while (rest != 0) {
        rest = rest / 10;
        count++;
    }
    return (count);
}

char *my_getstr(int nb)
{
    char *number = NULL;
    int negative = 0;
    int size = 0;
    int rest = 0;

    if (nb < 0) {
        nb = nb * (-1);
        negative = 1;
    }
    rest = nb;
    size = sizer(nb) + negative;
    number = malloc(sizeof(char) * (size + 1));
    number[size] = '\0';
    for (int i = size - 1; i >= negative; i--) {
        number[i] = rest % 10 + '0';
        rest = rest / 10;
    }
    if (negative == 1)
        number[0] = '-';
    return (number);
}
