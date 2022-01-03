/*
** EPITECH PROJECT, 2021
** rush2
** File description:
** error.c
*/

#include <unistd.h>

int my_compute_power_rec(int nb, int p);

void my_putchar( char c);

int my_put_nbr(int nb);

int my_putstr2(char const *str);

int error( float ac, char **argv)
{
    int i = 2;
    int d = 0;

    if (ac < 3) {
        write( 2, "Invalid input", 13);
        return 84;
    }

    if ((argv[2][0] >= 65 && argv[2][0] <= 90) ||
        (argv[2][0] >= 97 || argv[2][0] <= 122 )) {
    } else {
        write( 2, "Invalid input", 13);
        return 84;
    }
    while (argv[i][d] != '\0') {
        d += 1;
    }
    if (d >= 2) {
        write( 2, "Invalid input", 13);
        return 84;
    }
}

int my_display_modulo( float number, float l)
{
    if (number == l) {
        my_putstr2("100.00");
        return 0;
    }
    float x = number * 10000;
    x = x / l;
    int e = (int) x;
    int y = my_compute_power_rec( 10, 3);
    y = e / y;
    my_putchar(y + '0');
    y = my_compute_power_rec( 10, 2);
    y = e / y;
    y = (y % 10);
    my_putchar(y + '0');
    my_putchar('.');
    y = e / 10;
    y = (y % 10);
    my_putchar(y + '0');
    y = (e % 100);
    y = (y % 10);
    my_putchar(y + '0');
    return 0;
}

char *display_result( char letter, float number, float repeat, float l)
{
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr( number);
    my_putchar(' ');
    my_putchar('(');
    my_display_modulo( number, l);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}
