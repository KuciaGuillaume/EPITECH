/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** tests_buble.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (bubble_sort_array, index1_greater_than_index2)
{
    int i = 0;
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    int result[6] = { 1, 2, 3, 4, 5, 6 };

    bubble_sort_array(array, 6);
    while (i != 6) {
        cr_assert_eq(array[i], result[i]);
        i += 1;
    }
}
