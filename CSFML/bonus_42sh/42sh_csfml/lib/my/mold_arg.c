/*
** EPITECH PROJECT, 2021
** MINISHELL_V2
** File description:
** mold_arg.c
*/

#include "my.h"

char *remove_backline(char *str)
{
    int size = my_strlen(str) - 1;

    if (size < 0)
        return (str);
    if (str[size] == '\n')
        str[size] = '\0';
    return str;
}

int new_arglen(char *str, char separated)
{
    int result = 0;
    char *copy = my_strdup(str);

    copy = remove_backline(copy);
    while (copy[0] != '\0') {
        copy = move_to_next(copy, separated);
        result++;
    }
    return result;
}

char **mold_arg(char *str, bool backline, char sep)
{
    int size = new_arglen(str, sep);
    char **tab = malloc(sizeof(char *) * (size + 1));
    tab[size] = NULL;
    size = 0;

    if (backline)
        str = remove_backline(str);
    for (int i = 0; str[0] != '\0'; i++) {
        for (size = 0; str[size] != sep && str[size]; size++);
        tab[i] = my_strdup(grab(str, size));
        tab[i] = rm_useless(tab[i], ' ', false);
        str = move_to_next(str, sep);
    }
    return tab;
}
