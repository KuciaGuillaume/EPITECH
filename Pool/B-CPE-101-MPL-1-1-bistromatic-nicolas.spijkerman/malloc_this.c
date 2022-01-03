/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** malloc_this.c
*/

#include <stdlib.h>
#include "include/my.h"

void malloc_this(char **result, char *str)
{
    *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; i < my_strlen(str) + 1; i++) {
        result[0][i] = '\0';
    }
    for (int i = 0; str[i]; i++) {
        result[0][i] = str[i];
    }
    free(str);
}
