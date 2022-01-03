/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star etoile
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);
void star(int size);
void downcone(int size);
void hardcode(int size);

void ligne2(int size)
{
    int dpc = 0;
    int space = (size * 6) - 1;
    int cone = (size * 3) + size - 2;

    while (dpc != space) {
        if (dpc == (size * 2) + 1) {
            while (dpc != cone) {
                my_putchar(' ');
                dpc++;
            }
        } else {
            my_putchar('*');
            dpc++;
        }
    }
    my_putchar('\n');
    downcone(size);
}

void downcone(int size)
{
    int space = size * 3;
    int space2 = (size * 6) - 1;
    int dpc = 0;
    int cone = (size * 2) - 1;
    int hightcone = size;

    while (hightcone != 1) {

        while (dpc != space2) {
            if ((dpc == (space - cone) + (size - 1)) || dpc == space + (size - 3)) {
                my_putchar('*');
            }
            my_putchar(' ');
            dpc++;
        }
        my_putchar('\n');
        space--;
        cone = cone - 2;
        dpc = 0;
        hightcone--;
    }

    space = size * 3;
    while (dpc != space - 1) {
        my_putchar(' ');
        dpc++;
    }
    my_putchar('*');
    my_putchar('\n');
    dpc = 0;
    return;
}

void hardcode(int size)
{
    int spa = 3;
    int moove = 0;

    while (moove != spa) {
        my_putchar(' ');
        moove++;
    }
    my_putchar('*');
    my_putchar('\n');
    moove = 0;

    while (moove != 6) {
        if (moove == 3) {
            my_putchar(' ');
        }
        my_putchar('*');
        moove++;
    }
    my_putchar('\n');
    moove = 0;

    while (moove != 6) {
        if (moove == 1 || moove == 4) {
            my_putchar('*');
        }
        my_putchar(' ');
        moove++;
    }
    my_putchar('\n');
    moove = 0;

    while (moove != 6) {
       if (moove == 3) {
           my_putchar(' ');
       }
    my_putchar('*');
    moove++;
    }
    my_putchar('\n');
    moove = 0;

    while (moove != spa) {
        my_putchar(' ');
        moove++;
    }
    my_putchar('*');
    my_putchar('\n');
    return;
}
