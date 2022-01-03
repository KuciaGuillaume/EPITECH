/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** tests_rotate_left.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (rotate_left, index0_index_left)
{
    int i = 0;
    int array[6] = { 1, 2, 3, 4, 5, 6 };
    int result[6] = { 2, 3, 4, 5, 6, 1 };

    rotate_left(array, 6);
    while ( i != 6) {
        cr_assert_eq(array[i], result[i]);
        i += 1;
    }
}

Test (rotate_right, indexleft_index_0)
{
    int i = 0;
    int array[6] = { 1, 2, 3, 4, 5, 6 };
    int result[6] = { 6, 1, 2, 3, 4, 5 };

    rotate_right(array, 6);
    while ( i != 6) {
        cr_assert_eq(array[i], result[i]);
        i += 1;
    }
}
