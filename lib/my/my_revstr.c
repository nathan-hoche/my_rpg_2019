/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char temp;
    int s = 0;
    int f = 0;

    for (;str[s] != '\0'; s++);
    for (int f = 0; f < s; f++) {
        s--;
        temp = str[f];
        str[f] = str[s];
        str[s] = temp;
    }
    return (str);
}