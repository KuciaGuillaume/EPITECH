/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** pop.c
*/

#include "include/pimp_my_algo.h"

void pop_decale(int *array1, int size)
{
    int i = size;

    while (i != 0) {
        i -= 1;
        if (i != 0)
            array1[i] = array1[i - 1];
    }
}

void pop(int *array1, int *array2, int size)
{
    int i = 0;
    if (array1[0] != (-1))
        pop_decale(array1, size);
    array1[0] = array2[0];
    while (i != size - 1) {
        i += 1;
        if (i != size - 1)
            array2[i - 1] = array2[i];
        else {
            array2[i - 1] = array2[i];
            array2[i] = (-1);
        }
    }
}