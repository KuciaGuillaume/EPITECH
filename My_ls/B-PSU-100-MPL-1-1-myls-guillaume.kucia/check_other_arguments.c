/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** check_other_arguments.c
*/

#include "include/my.h"

char *check_other_argument(option_t *opt, char **av)
{
    int i = opt->passed;

    while (i != 0) {
        av += 1;
        i -= 1;
    }
    return av[0];
}