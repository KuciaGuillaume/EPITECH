/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** number.c
*/

int number(char **str_ptr)
{
    int i = 0;
    int result = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] >= '0' && (*str_ptr)[i] <= '9') {
            result = result * 10;
            result = result + (*str_ptr)[i] - 48;
            i += 1;
        } else {
            *str_ptr = (&(*str_ptr)[i]);
            return result;
        }
    }
    *str_ptr = (&(*str_ptr)[i]);
    return result;
}
