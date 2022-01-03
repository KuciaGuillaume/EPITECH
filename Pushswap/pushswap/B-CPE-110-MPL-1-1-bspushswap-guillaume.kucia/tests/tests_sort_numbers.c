/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** tests_sort_numbers.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (sort_numbers, push_test)
{
    int i = 0;
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    int array2[6] = { -1, -1, -1, -1, -1, -1};
    int result[6] = { 1, 2, 3, 4, 5, 6};

    sort_numbers(array, array2, 6);
    while (i != 6) {
        cr_assert_eq(array[i], result[i]);
        i += 1;
    }
}