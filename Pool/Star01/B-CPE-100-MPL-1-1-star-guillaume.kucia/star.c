/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star etoile
*/

#include <stdio.h>
#include <unistd.h>

void ligne(int size);
void balise(int size);
void DownStar(int size);
void ligne2(int size);
void downcone(int size);
void hardcode(int size);

void my_putchar(char c);

void star(unsigned int size)
{
    if (size <= 0) {
        my_putchar('\n');
        return;
    }
    if (size == 1) {
        hardcode(size);
        return;
    }
    int space = size * 3;
    int dpc = 0;
    int cone = 1;
    int hightcone;
    hightcone = size;
    while (dpc != space - 1) {
        my_putchar(' ');
        dpc++;
    }
    my_putchar('*');
    my_putchar('\n');
    dpc = 0;
    while (hightcone != 1) {

        while (dpc != space) {
            if ((dpc == space - 1 - cone) || dpc == space - 1) {
                my_putchar('*');
            }
            my_putchar(' ');
            dpc++;
        }
        my_putchar('\n');
        space++;
        cone = cone + 2;
        dpc = 0;
        hightcone--;

    }
    ligne(size);
}



void ligne(int size)
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
    balise(size);
}

void balise(int size)
{
    int dpc = 0;
    int baldeb = 1;
    int reverse = 0;
    int balfin = (size * 6) - 4;
    int space = (size * 6) - 1;
    int hight_balise = size * 2;

    while (hight_balise != 1) {
        while (dpc != space) {
            if (dpc == baldeb || dpc == balfin) {
                my_putchar('*');
            }
            my_putchar(' ');
            dpc++;
        }
        dpc = 0;
        if (baldeb == size) {
            reverse = 1;
        }
        if (reverse == 0) {
            baldeb++;
            balfin--;
        } else {
            baldeb--;
            balfin++;
        }
        hight_balise--;
        my_putchar('\n');
    }
    ligne2(size);
}
