/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-rush2-guillaume-kucia
** File description:
** step1.c
*/

#include <unistd.h>

int my_put_nbr(int nb);

int my_modulo( float letter, float i);

void my_putchar( char c)
{
    write(1, &c, 1);
}

int error( float argcc, char **argv)
{
    if (argcc < 3) {
        write( 2, "Invalid input", 13);
        return 84;
    }
    if ((argv[2][0] >= 65 && argv[2][0] <= 90) || (argv[2][0] >= 97 || argv[2][0] <= 122 )) {
    } else {
        write( 2, "Invalid input", 13);
        return 84;
    }

}

char *result( char letter, float number, float repeat, float l)
{
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr( number);
    my_putchar(' ');
    my_putchar('(');
    my_modulo( number, l);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

int main( int argc, char **argv)
{
    int argccc = argc;
    float argcc = (float)argc;

    float stop = error( argc, argv);
    if (stop == 0) { return 0; }
    int i = 0;
    int l = 0;
    int y = 1;
    float number = 0;
    int repeat = 0;

    while (argv[2 + repeat] != NULL) {

        char letter = argv[2 + repeat][0];

        while (argv[y][i] != '\0') {
            if ((argv[y][i] == letter) || (argv[y][i] == letter + 32) || (argv[y][i] == letter - 32)) {
                number += 1;
                i += 1;
                l += 1;
            } else {
                if ((argv[y][i] > 64 && argv[y][i] < 91) || (argv[y][i] > 96 && argv[y][i] < 123)) {
                    l += 1;
                }
                i += 1;
            }
        }
        result( letter, number, repeat, l);
        repeat += 1;
        l = 0;
        i = 0;
        number = 0;
    }
}
