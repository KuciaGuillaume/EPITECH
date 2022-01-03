/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** push.c
*/

#include "include/pimp_my_algo.h"

void push_decale(int *array2, int size)
{
    int i = size;

    while (i != 0) {
        i -= 1;
        if (i != 0)
            array2[i] = array2[i - 1];
    }
}

void push(int *array1, int *array2, int size)
{
    int i = 0;
    if (array2[0] != (-1))
        push_decale(array2, size);
    array2[0] = array1[0];
    while (i != size - 1) {
        i += 1;
        if (i != size - 1)
            array1[i - 1] = array1[i];
        else {
            array1[i - 1] = array1[i];
            array1[i] = (-1);
        }
    }
}
