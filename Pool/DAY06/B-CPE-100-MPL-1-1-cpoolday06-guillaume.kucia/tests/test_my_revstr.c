/*
** EPITECH PROJECT, 2021
** test_my_revstr.c
** File description:
** Day06 task04
*/

#include <criterion/criterion.h>

Test(my_revstr, reverse)
{	
	char str[] = "Hello";
	my_revstr(str);
	cr_assert_str_eq(str, "olleH");
}
