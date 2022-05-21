/*
** EPITECH PROJECT, 2021
** MINISHELL_V2
** File description:
** grab.c
*/

#include "cstr.h"
#include "gen.h"

char *cstr_grab(char *str, char sep)
{
    int i = 0;

    for (; str[0] == sep; str++);
    for (; str[i] != sep && str[i]; i++);
    str[i] = '\0';
    return str;
}
