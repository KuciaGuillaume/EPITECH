/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** bubble_sort_array.c
*/

#include "include/pimp_my_algo.h"

void bubble_sort_array(int *array, int size)
{
    int i = 1;

    while (i != size) {
        if (array[i] < array[i - 1] && i != 0) {
            swap_elem(array, i, i - 1);
            i = 0;
        } else
            i += 1;
    }
}
