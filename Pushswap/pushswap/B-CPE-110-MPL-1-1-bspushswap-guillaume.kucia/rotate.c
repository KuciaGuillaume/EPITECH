/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** rotate_left.c
*/

#include "include/pimp_my_algo.h"

void rotate_right(int *array, int size)
{
    int temp = array[size - 1];
    int i = (size - 1);

    while (i != 0) {
        i -= 1;
        array[i + 1] = array[i];
    }
    array[0] = temp;
}

void rotate_left(int *array, int size)
{
    int temp = array[0];
    int i = 1;

    while (i != size) {
        array[i - 1] = array[i];
        i += 1;
    }
    array[size - 1] = temp;
}
