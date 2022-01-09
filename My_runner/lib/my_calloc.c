/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** my_calloc.c
*/

#include <stdlib.h>

char *my_calloc(char *str, int n)
{
    str = malloc(sizeof(char) * (n + 1));
    int i;

    for (i = 0; i != n; i += 1)
        str[i] = '.';
    str[i] = '\0';
    return str;
}
