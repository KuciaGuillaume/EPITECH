/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Day08 task01
*/

#include <stdlib.h>
#include "my.h"
#include <unistd.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int f = 0;
    char *tableau = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[i] != '\0') {
        tableau[f] = src[i];
        f++;
        i++;
    }
    tableau[i] = '\0';
    return tableau;
}
