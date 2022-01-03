/*
** EPITECH PROJECT, 2021
** test_my_strstr.c
** File description:
** Day06 task05
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, locate_a_substring)
{
    char world[5] = "Hello" ;
    cr_assert_str_eq(my_strstr("ergdHello", world), "Hello");
}
