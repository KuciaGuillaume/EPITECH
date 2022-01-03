/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** error.c
*/

int set_error(char const *str, int i)
{
    i += 1;
    char e = str[i];

    if (e != 'x' && e != 'X' && e != 'p' && e != 'o' && e != 'b' &&
    e != '%' && e != 'u' && e != 'S' && e != 's' && e != 'd' &&
    e != 'c') {
        return 84;
    }
    return 0;
}

int error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '%')
            return set_error(str, i);
        i += 1;
    }
    return 0;
}