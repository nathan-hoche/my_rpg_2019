/*
** EPITECH PROJECT, 2020
** MY_STRDUP
** File description:
** allocates memory and puts the source string in it
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *result = NULL;
    int size = 0;

    for (int i = 0; src[i]; i++)
        size++;
    result = malloc(sizeof(char) * (size + 1));
    if (result == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++)
        result[i] = src[i];
    return (result);
}