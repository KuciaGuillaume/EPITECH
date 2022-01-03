/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** sort_numbers.c
*/

#include "include/pimp_my_algo.h"

int find_less_number(int *array1, int size)
{
    int i = 0;
    int pos = 0;
    int min = __INT_MAX__;

    while (i != size) {
        if (array1[i] <= min && array1[i] >= 0) {
            pos = i;
            min = array1[i];
        }
        i += 1;
    }
    return pos;
}

void set_min_to_first_index(int *array1, int size, int pos_min)
{
    while (pos_min != 0) {
        rotate_left(array1, size);
        pos_min -= 1;
    }
}

void array2_clean(int *array1, int *array2, int size)
{
    int i = 0;
    while (i != size) {
        if (array2[0] != (-1))
            pop(array1, array2, size);
        i += 1;
    }
}

void sort_numbers(int *array1, int *array2, int size)
{
    int i = 0;
    int pos_min = 0;
    array2_clean(array1, array2, size);
    while (i != size) {
        pos_min = find_less_number(array1, size);
        set_min_to_first_index(array1, size, pos_min);
        push(array1, array2, size);
        i += 1;
    }
    for (i = 0; i != size; i++)
        pop(array1, array2, size);
}
