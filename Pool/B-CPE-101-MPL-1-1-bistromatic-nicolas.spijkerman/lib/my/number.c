/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** number.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *number(char **str)
{
    int size = 0;
    char *result;

    while ('0' <= str[0][size] && str[0][size] <= '9') {
        size++;
    }
    result = malloc(sizeof(char) * size);
    size = 0;
    while ('0' <= **str && **str <= '9') {
        result[size++] = **str;
        (*str)++;
    }
    return result;
}
