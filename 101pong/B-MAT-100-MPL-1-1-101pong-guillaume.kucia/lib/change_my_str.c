/*
** EPITECH PROJECT, 2021
** B-MAT-100-MPL-1-1-101pong-guillaume.kucia
** File description:
** calc_my_float.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *separate_my_str(char *str, int x)
{
    char *strx = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;
    int e = 0;

    while (str[i] != '.') {
        if (x == 1) {
            i += 1;
        } else {
            strx[i] = str[i];
            i += 1;
        }
    }
    if (x == 0)
        strx[i] = '\0';
    i += 1;
    while (str[i] != '\0' && x == 1) {
        strx[e] = str[i];
        i += 1;
        e += 1;
    }
    return strx;
}

float change_my_str(struct pong *vector, char *str)
{
    char *str1 = separate_my_str(str, 0);
    char *str2 = separate_my_str(str, 1);
    float value = 0.00;

    vector->xx1 = create_my_float(str1, vector);
    vector->xx2 = create_my_float(str2, vector);
    while (vector->xx2 >= 1) {
        vector->xx2 /= 10;
    }
    if (vector->xx1 < 0) {
        vector->xx1 *= (-1);
        value = (vector->xx1 + vector->xx2);
        value *= (-1);
        return value;
    }
    return (vector->xx1 + vector->xx2);
}
