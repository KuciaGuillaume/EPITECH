/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** pushswap.c
*/

#include "include/pimp_my_algo.h"

void swap_elem(int *array, int index1, int index2)
{
    int i = array[index1];

    array[index1] = array[index2];
    array[index2] = i;
}
