/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    char *new = NULL;
    int i = 0;
    int j = 0;
    int a = 0;

    for (;dest[i] != '\0';i++);
    for (;src[j] != '\0';j++);
    new = malloc(sizeof(char)* (i+j+1));
    for (;dest[a] != '\0'; a++)
        new[a] = dest[a];
    for (int b = 0; src[b] != '\0'; b++)
        new[a+b] = src[b];
    new[i+j] = '\0';
    free(dest);
    return (new);
}