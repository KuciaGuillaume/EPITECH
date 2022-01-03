/*
** EPITECH PROJECT, 2021
** B-MAT-100-MPL-1-1-102architect-alice.hamadi
** File description:
** main.c
*/

#include "include/my.h"
#include <stdio.h>

void display_description(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            printf("USAGE\n"
                   "   ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\n"
                   "DESCRIPTION\n"
                   "    x   abscissa of the original point\n"
                   "    y   ordinate of the original point\n\n"
                   "    transfo arg1 [arg2]\n"
                   "    -t i j translation along vector (i, j\n"
                   "    -z m n scaling by factors m (x-axis) and n (y-axis)\n"
                   "    -r d   rotation centered in 0 by a d degree angle\n"
                   "    -s     reflection over the axis passing through 0 with an inclination\n"
                   "           angle of d degrees\n");
        }
    }

}

void flags(char *av, storage_t *storage)
{
    if (av[0] != '-')
        return;
    if (av[1] == 't' && av[2] == '\0') {
        storage->t = 1;
        storage->nflags += 1;
    }
    if (av[1] == 'z' && av[2] == '\0') {
        storage->z = 1;
        storage->nflags += 1;
    }
    if (av[1] == 'r' && av[2] == '\0') {
        storage->r = 1;
        storage->nflags += 1;
    }
    if (av[1] == 's' && av[2] == '\0') {
        storage->s = 1;
        storage->nflags += 1;
    }
}

void init(storage_t *storage)
{
    storage->t = 0;
    storage->z = 0;
    storage->r = 0;
    storage->s = 0;
    storage->nflags = 0;
}

int check_arguments(int ac, char **av __attribute__((unused)), storage_t *storage)
{
    int i = 3;
    int a = 0;

    if (storage->t == 1)
        i += 3;
    if (storage->z == 1)
        i += 3;
    if (storage->r == 1)
        i += 2;
    if (storage->s == 1)
        i += 2;
    if (i != ac) {
        if (i > ac)
            printf("Manque d'arguments !\n");
        if (i < ac)
            printf("Trop d'arguments !\n");
        return 84;
    }
    for (int e = 1; av[e] != NULL; e += 1) {
        while (av[e][a] != '\0') {
            if (av[e][0] == '-')
                break;
            if (av[e][1] == '-')
                a += 1;
            if (av[e][a] < '0' || av[e][a] > '9') {
                return 84;
            }
            a += 1;
        }
        a = 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    storage_t storage;
    display_description(ac, av);
    init(&storage);
    for (int i = 1; av[i] != NULL; i += 1)
        flags(av[i], &storage);
    if (check_arguments(ac, av, &storage) == 84)
        return 84;
    return 0;
}