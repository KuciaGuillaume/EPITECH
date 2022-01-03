/*
** EPITECH PROJECT, 2021
** Day03task05
** File description:
** function
*/

#include <unistd.h>

void my_putchar (char ch);

int comb_printing (int a, int b ,int c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    if (a==55 && b==56 && c==57) {
    } else {
        my_putchar(44);
        my_putchar(32);
    } return (0);
}

int my_print_comb(void)
{
    int a = 48;
    int b = 49;
    int c = 50;
    while (a < 56) {
        while (b < 57) {
            while (c < 58) {
                comb_printing(a, b, c);
                c++;
            }
            b++;
            c = b + 1;
        }
        b = a + 1;
        a++;
    } return (0);
}