/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** find_errors
*/

#include "include/my.h"

int loop_errors_calc(char **av, int *i, int *a)
{
    if ((av[*a][*i] < '0' || av[*a][*i] > '9')) {
        if (*i != 0)
            return 84;
        if (*i == 0 && av[*a][0] != '-')
            return 84;
    }
    *i += 1;
    return 0;
}

int loop_errors(char **av, int a)
{
    int i = 0;
    while (av[a][i] != '\0') {
        if (loop_errors_calc(av, &i, &a) == 84)
            return 84;
    }
    return 0;
}

int find_errors(int ac, char **av, int *display)
{
    int a = 1;

    if (ac == 1) {
        my_putchar('\n');
        return 84;
    } else if (ac <= 2)
        return 0;
    if (my_strcmp(av[ac - 1], ("-v")) == 0) {
        display[0] = 1;
        ac -= 1;
    } else if (my_strcmp(av[ac - 1], ("-v-r")) == 0) {
        display[0] = 2;
        ac -= 1;
    }
    while (a != ac) {
        if (loop_errors(av, a) == 84)
            return 84;
        a += 1;
    }
    return 0;
}
