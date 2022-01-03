/*
** EPITECH PROJECT, 2021
** my_print_comb2.c
** File description:
** task06
*/

#include <unistd.h>


void my_putchar(char c);


int dog(int a, int b)
{
    if ( a > 9 || b > 9 )
    {
        my_putchar(a/10 + 48);
        my_putchar(a%10 + 48);
        my_putchar(' ');
        my_putchar(b/10 + 48);
        my_putchar(b%10 + 48);
        my_putchar(',');
        my_putchar(' ');
    }
    else
    {
        my_putchar(a/10 + 48);
        my_putchar(a%10 + 48);
        my_putchar(' ');
        my_putchar(b/10 + 48);
        my_putchar(b%10 + 48);
        my_putchar(',');
        my_putchar(' ');
    }

    if ( a == 98 || b == 99 )
    {
        my_putchar(a/10 + 48);
        my_putchar(a%10 + 48);
        my_putchar(' ');
        my_putchar(b/10 + 48);
        my_putchar(b%10 + 48);
        my_putchar(',');
        my_putchar(' ');
    }
    return (0);
}



int my_print_comb2(void)
{
    int a = 0;
    int b = 0;

    while( a != 98 || b !=99 )
    {
        b++;
        if ( b == 100 )
        {
            a++;
            b = a + 1;
        }
        dog (a, b);

    }
    return (0);

}
    

