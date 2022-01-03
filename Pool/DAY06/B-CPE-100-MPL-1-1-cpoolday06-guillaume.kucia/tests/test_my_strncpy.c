/*
** EPITECH PROJECT, 2021
** test_my_strncpy.c
** File description:
** Day06 task04
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
