/*
** EPITECH PROJECT, 2021
** concat_params.c
** File description:
** Day08 task02
*/

#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>

int my_putstr(char const *str);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int calcule(int size, char *argv[])
{
    int i = 0;
    int f = 0;
    size = 0;

    while (argv[i] != NULL) {
        while (argv[i][f] != '\0') {
            f = f + 1;
        }
        size = (size + f) + 1;
        i = i + 1;
        f = 0;
    }
    return size;
}

char *concat_params(int argc, char *argv[])
{
    int i = 0;
    int f = 0;
    int e = 0;
    int s = 0;
    int size = 0;
    size = calcule(size, argv);
    char *tableau = malloc((sizeof(char) * (size)) + 1);

    while ( i != argc) {
        while (argv[f][s] != '\0') {
            tableau[e] = argv[f][s];
            e += 1;
            s += 1;
        }
        tableau[e] = '\n';
        e += 1;
        s = 0;
        f = f + 1;
        i = i + 1;
    }
    tableau[e] = '\0';
    return tableau;
}
