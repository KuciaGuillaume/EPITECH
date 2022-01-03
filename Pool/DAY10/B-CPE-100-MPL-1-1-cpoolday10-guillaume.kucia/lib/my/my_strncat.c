/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** Day07 task03
*/

#include <unistd.h>

#include <stdio.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int m = 0;
    int size = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[m] != '\0') {
        if (size != nb) {
        dest[i] = src[m];
        i++;
        m++;
        size++;
        } else {
            return dest;
        }
    }
    return dest;
}
