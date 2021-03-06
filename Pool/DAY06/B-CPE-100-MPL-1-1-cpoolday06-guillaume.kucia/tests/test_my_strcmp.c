/*
** EPITECH PROJECT, 2021
** test_my_strcmp.c
** File description:
** Day0 task06
*/

#include <unistd.h>
#include <criterion/criterion.h>

char *my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, Compare_two_strings)
{
    char world[5] = "hello";
    char world2[5] = "Hello";
    cr_assert_str_eq(my_strcmp(world2, world), 1);
}

