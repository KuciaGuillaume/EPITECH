/*
** EPITECH PROJECT, 2021
** rush2.c
** File description:
** DAY10 rush2
*/

#include <unistd.h>

#include <stdlib.h>

int my_display_modulo( float letter, float i);

char *display_result( char letter, float number, float repeat, float l);

int error( float ac, char **argv);

int main( int argc, char **argv)
{
    float ac = (float)argc;
    float number = 0;
    char letter;
    int i = 0;
    int l = 0;
    int y = 1;
    int repeat = 0;
    error( ac, argv);

    while (argv[2 + repeat] != NULL) {
        char letter = argv[2 + repeat][0];
        while (argv[y][i] != '\0') {
            if ((argv[y][i] == letter) || (argv[y][i] == letter + 32) ||
                (argv[y][i] == letter - 32)) {
                number += 1;
                i += 1;
                l += 1;
            } else {
                if ((argv[y][i] > 64 && argv[y][i] < 91) ||
                    (argv[y][i] > 96 && argv[y][i] < 123)) {
                    l += 1;
                }
                i += 1;
            }
        }
        display_result( letter, number, repeat, l);
        repeat += 1;
        l = 0;
        i = 0;
        number = 0;
    }
}

