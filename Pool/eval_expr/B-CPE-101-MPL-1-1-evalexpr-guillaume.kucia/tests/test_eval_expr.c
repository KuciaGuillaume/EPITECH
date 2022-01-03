/*
** EPITECH PROJECT, 2021
** eval_exprexpr
** File description:
** test_eval_exprexpr.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "../lib/my/my.h"

int eval_expr(char **str);

Test(eval_expr, calcul_the_string)
{
    char *test = "123+45";

    cr_assert_eq(eval_expr(&test), 168);
}