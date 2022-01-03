/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-guillaume.kucia
** File description:
** tests_push.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pimp_my_algo.h"

Test (push, push_test)
{
    int i = 0;
    int array[6] = { 1, 2, 3, 4, 5, 6 };
    int array2[6] = { 5, 4, -1, -1, -1, -1};
    int result[6] = { 1, 5, 4, -1, -1, -1};

    push(array, array2, 6);
    while ( i != 6) {
        cr_assert_eq(array2[i], result[i]);
        i += 1;
    }
}