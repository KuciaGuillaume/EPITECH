/*
** EPITECH PROJECT, 2021
** MINISHELL_V2
** File description:
** grab.c
*/

#include "my.h"

char *grab(char *str, int n)
{
    char *result = malloc(sizeof(char) * n + 1);
    result[n] = '\0';

    for (int i = 0; i != n; i++)
        result[i] = str[i];
    return result;
}

char *move_to_next(char *str, char pipe)
{
    for (; str[0] != pipe && str[0] != '\0'; str++);
    for (; str[0] == pipe && str[0] != '\0'; str++);
    return str;
}
