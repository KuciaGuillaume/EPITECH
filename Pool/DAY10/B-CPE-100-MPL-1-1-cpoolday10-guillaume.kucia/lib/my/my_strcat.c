/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** Day07 task02
*/

#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int m = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[m] != '\0') {
        dest[i] = src[m];
        i++;
        m++;
    }
    return dest;
}
