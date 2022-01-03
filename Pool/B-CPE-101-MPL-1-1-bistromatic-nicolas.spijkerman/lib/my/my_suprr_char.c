/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_suprr_char.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int calc_delete(char *str, char delete)
{
    int i = 0;
    int e = 0;

    while (str[e] != '\0') {
        if (str[e] == delete) {
            i += 1;
        }
        e += 1;
    }
    return i;
}

char *suppr_char(char *str, char delete)
{
    int i = calc_delete(str, delete);
    int e = 0;

    bistro suppr;
    suppr.result = malloc((sizeof(char) * (my_strlen(str) - i)) + 1);
    suppr.result[(my_strlen(str) - i) + 1] = '\0';
    i = 0;

    while (e < (my_strlen(str))) {
        if (str[i] != delete) {
            suppr.result[e] = str[i];
            e += 1;
        }
        i += 1;
    }
    return suppr.result;
}
