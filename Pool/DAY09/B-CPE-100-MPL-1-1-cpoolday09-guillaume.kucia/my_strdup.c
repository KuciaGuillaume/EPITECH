/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Day08 task01
*/

#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

int my_strlen2(char const *src)
{
    int a = 0;

    while (src[a] != '\0')
    {
        a = a + 1;
    }
    return (a);
}

char *my_strdup(char const *src)
{
    int i = 0;
    int f = 0;
    char *tableau = malloc(sizeof(char) * (my_strlen2(src) + 1));

    while (src[i] != '\0') {
        tableau[f] = src[i];
        f++;
        i++;
    }
    tableau[i] = '\0';
    return tableau;
}
