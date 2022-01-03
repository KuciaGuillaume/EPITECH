/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_putchar
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
