/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** tests_swap.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (swap_elem, index1_greater_than_index2)
{
    int array[6] = { 1, 2, 3, 4, 5, 6 };
    int index1 = 2;
    int index2 = 4;

    swap_elem(array, index1, index2);
    cr_assert_eq(array[index1], 5);
    cr_assert_eq(array[index2], 3);
}
