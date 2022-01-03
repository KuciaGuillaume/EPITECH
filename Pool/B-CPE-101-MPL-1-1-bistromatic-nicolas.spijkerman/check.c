/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** check.c
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistromatic.h"

static int check_in_syntax(char c, char *syntax)
{
    for (int i = 0; syntax[i]; i++) {
		if (syntax[i] == c)
			return 1;
	}
	return 0;
}

static int check_in_base(char c, char *base, char *syntax)
{
	for (int i = 0; base[i]; i++) {
		if (check_in_syntax(c, syntax) || base[i] == c)
			return 1;
	}
	return 0;
}

static int is_in_base(char c, char *base)
{
	for (int i = 0; base[i]; i++) {
		if (c == base[i])
			return i;
	}
	return -1;
}

void check_expr(char *expr, char *base, char *syntax)
{
	int loop = 0;
	int parenth_l = 0;
	int parent_r = 0;

	while (expr[loop] && check_in_base(expr[loop], base, syntax)) {
		if (expr[loop] == syntax[0])
			parenth_l++;
		if (expr[loop] == syntax[1])
			parent_r++;
		loop++;
	}
	if (parenth_l != parent_r || loop < my_strlen(expr)) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_CHECK);
	}
    loop = -1;
    while (expr[++loop]) {
        if (expr[loop] == syntax[0] && (is_in_base(expr[loop - 1], base) != -1)) {
            my_putstr(SYNTAX_ERROR_MSG);
		    exit(EXIT_CHECK); 
        }
    }
}
