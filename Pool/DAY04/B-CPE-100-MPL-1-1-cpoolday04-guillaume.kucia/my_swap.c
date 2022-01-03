/*
** EPITECH PROJECT, 2021
** Day04task01
** File description:
** function - my_swap
*/

#include <unistd.h>
#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}