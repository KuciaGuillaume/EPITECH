/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** mem_alloc.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *mem_alloc(char const *a, char const *b)
{
    char *alloc = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)) + 1);
    int val = my_strlen(a) + my_strlen(b);
    int i = 0;
    int e = 0;
    alloc[val] = '\0';

    while (i != val) {
        if (i < my_strlen(a)) {
            alloc[i] = a[i];
        } else {
            alloc[i] = b[e];
            e += 1;
        }
        i += 1;
    }
    return alloc;
}
