/*
** EPITECH PROJECT, 2021
** rush1-4.c
** File description:
** Rush4 task04
*/

#include <stdio.h>
#include <unistd.h>
void rush2(int x, int y);
void colonnes(int x, int y);
char my_putchar(char c);

void rush(int x, int y)
{
    int l = x;
    int h1 = y;
    h1 = h1 + 0;

    if (x == 0 || y == 0) {
        write(2,"Invalid size\n", 13);
        return;
    }
    if (x == 1 || y == 1) {
        my_putchar('B');
    } else {
        my_putchar('A');
    }
    if (x != 1) {
        l = l - 1;
    }

    while ( l != 1 ) {
        my_putchar('B');
        l = l - 1;
    }
    if (x > 1) {
        if (x == 1 || y == 1) {
            my_putchar('B');
        } else {
            my_putchar('C');
        }
    }
    my_putchar('\n');
    if (y != 1) {
        colonnes(x, y);
    } else {
        return;
    }
}

void colonnes(int x, int y)
{
    int h = y;

    while ( h != 2 ) {
        int l2 = x;
        my_putchar('B');
    if (x != 1) {
        l2 = l2 - 1;
    }

    while (l2 != 1) {
        my_putchar(' ');
        l2 = l2 - 1;
    }
    if (x > 1) {
        my_putchar('B');
    }
    my_putchar('\n');
    h = h - 1;
    }
    rush2(x, y);

}

void rush2(int x, int y)
{
    int l = x;
    int h1 = y;
    h1 = h1 + 0;

    if (x == 1 || y == 1) {
        my_putchar('B');
    } else {
        my_putchar('A');
    }
    if (x != 1) {
        l = l - 1;
    }

    while ( l != 1 ) {
	my_putchar('B');
	l = l - 1;
    }
    if (x > 1) {
        if (x == 1 || y == 1) {
            my_putchar('B');
        } else {
            my_putchar('C');
        }
    }
    my_putchar('\n');
    return;

}
