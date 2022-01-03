/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** Day06 task02
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int l = 0;

    while (src[l] != '\0' && l < n) {
        dest[l] = src[l];
        l++;
    }
    return dest;
}
