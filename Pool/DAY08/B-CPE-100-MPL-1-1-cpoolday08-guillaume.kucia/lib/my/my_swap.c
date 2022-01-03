/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** Day04
*/

#include <unistd.h>

#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
