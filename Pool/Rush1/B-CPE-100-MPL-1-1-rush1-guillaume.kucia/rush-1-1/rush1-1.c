/*
** EPITECH PROJECT, 2021
** rush1-1.c
** File description:
** Rush1 Task01
*/

#include <stdio.h>
#include <unistd.h>
void rush2(int x, int y);
void colonnes(int x, int y);
void my_putchar(char c);

void rush(int x, int y)
{
    int l = x;
    int h1 = y;
    h1 = h1 + 0;

    if (x == 0 || y == 0) {
        write(2,"Invalid size\n", 13);
        return;
    }
    my_putchar('o');
    if (x != 1) {
        l = l - 1;
    }

    while ( l != 1 ) {
        my_putchar('-');
        l = l - 1;
    }
    if (x > 1) {
        my_putchar('o');
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
        my_putchar('|');
    if (x != 1) {
        l2 = l2 - 1;
    }

    while (l2 != 1) {
        my_putchar(' ');
        l2 = l2 - 1;
    }
    if (x > 1) {
        my_putchar('|');
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

    my_putchar('o');
    if (x != 1) {
        l = l - 1;
    }

    while ( l != 1 ) {
	my_putchar('-');
	l = l - 1;
    }
    if (x > 1) {
	my_putchar('o');
    }
    my_putchar('\n');
    return;

}
