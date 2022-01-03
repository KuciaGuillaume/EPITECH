/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** parse_digits.c
*/

int number(char **str_ptr);
int is_digit(char c);

int parse_digits(char **str)
{
    int r = 0;

    if (is_digit(**str) || **str == '-') {
        r = number(str);
    }
    return r;
}
