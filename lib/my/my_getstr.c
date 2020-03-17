/*
** EPITECH PROJECT, 2019
** my_getstr.c
** File description:
** getstr from int
*/
#include <stdlib.h>
#include "../../include/my.h"

static char *except(int nb)
{
    char *result = malloc(sizeof(int)* nb + 2);

    if (nb == 0)
        result[0] = '0';
    result[1] = '\0';
    return (result);
}

char *my_getstr(int nb)
{
    int temp = 0;
    int i = 0;
    int sign = 0;

    if (nb == 0)
        return ("0\0");
    if (nb < 0) {
        nb = nb * -1;
        sign == 1;
    }
    char *result = except(nb);
    for (;nb > 0; i++) {
        temp = nb % 10;
        temp = temp + 48;
        nb = nb / 10;
        result[i] = temp;
    }
    result[i] = '\0';
    return (my_revstr(result));
}