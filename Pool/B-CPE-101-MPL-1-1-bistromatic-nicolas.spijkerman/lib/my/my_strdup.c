/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strdup.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(src) + 1));
    char *result = temp;

    while (*src) {
        *temp++ = *src++;
    }
    *temp = '\0';
    return result;
}
