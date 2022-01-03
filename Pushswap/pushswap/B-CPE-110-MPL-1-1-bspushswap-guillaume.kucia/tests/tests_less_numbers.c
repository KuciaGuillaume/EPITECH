/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** tests_less_numbers.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (find_less_number, index0_index_left)
{
    int i = 0;
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    int result = 5;

    i = find_less_number(array, 6);
    cr_assert_eq(i, result);
}

Test (set_min_to_first, index0_index_left)
{
    int i = 0;
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    int result[6] = { 1, 6, 5, 4, 3, 2 };

    set_min_to_first_index(array, 6, 5);
    while (i != 6) {
        cr_assert_eq(array[i], result[i]);
        i += 1;
    }
}