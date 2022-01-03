/*
** EPITECH PROJECT, 2021
** test_strncmp.c
** File description:
** Day06 task07
*/

#include <unistd.h>
#include <criterion/criterion.h>

char *my_strncmp(char const *s1, char const *s2, int *n);

Test(my_strncmp, Compare_two_strings02)
{
    char word[5] = "hello";
    char word[5] = "Hello";
    cr_assert_arr_eq(my_strncmp(world2, world, 2), 1);
}
