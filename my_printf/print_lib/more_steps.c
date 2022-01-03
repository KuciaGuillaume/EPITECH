/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** More_steps.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdarg.h>
#include <unistd.h>

void verif_tags(char *my_str, int *i, struct printf *format)
{
    if (my_str[*i] == '%')
        format->valide_sp = 0;
    *i += 1;
    if (my_str[*i] == '#') {
        format->tags = '#';
        *i += 1;
    }
}

void more_steps(int *i, char *my_str, struct printf *format)
{
    if (my_str[*i] == '#') {
        format->tags = '#';
        *i += 1;
    }
}