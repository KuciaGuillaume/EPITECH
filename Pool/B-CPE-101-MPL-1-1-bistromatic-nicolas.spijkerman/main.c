/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"
#include "include/my.h"

void check_expr(char *expr, char *base, char *syntax);

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    int verif = 0;

    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i]; i++) {
        for (int j = 0; ops[j]; j++) {
            i == j ? j++ : j;
            (ops[i] == ops[j]) && (i != j) ? verif = 1 : verif ;
        }
    }
    if (verif == 1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    int verif = 0;

    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (int i = 0; b[i]; i++) {
        for (int j = 0; b[j]; j++) {
            i == j ? j++ : j ;
            (b[i] == b[j]) && (i != j) ? verif = 1 : verif ;
        }
    }
    if (verif == 1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }

}

static void check_base_syntax(char *base, char *syntax)
{
    int verif = 0;

    for (int i = 0; base[i]; i++) {
        for (int j = 0; syntax[j]; j++) {
            base[i] == syntax[j] ? verif = 1 : verif ;
        }
    }
    if (verif) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE_OPS);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    check_base_syntax(av[1], av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_expr(expr, av[1], av[2]);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}
