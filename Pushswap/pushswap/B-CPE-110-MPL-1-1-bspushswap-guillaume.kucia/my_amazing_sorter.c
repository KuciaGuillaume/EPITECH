/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** my_amazing_sorter.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include/pimp_my_algo.h"

void loop_array(int *array, int size)
{
    int e = 0;
    printf("list -> {");
    while (e != size) {
        if (e != size - 1)
            printf(" %d, ", array[e]);
        else
            printf(" %d ", array[e]);
        e += 1;
    }
    printf("} | Coded by OneLife\n----------------"
    "------------------------------------\n");
}

void my_amazing_sorter(int *array, int size)
{
    int i = 1;

    loop_array(array, size);
    while (i != size) {
        if (array[i] < array[i - 1] && i != 0) {
            swap_elem(array, i, i - 1);
            printf("| swap %d -> %d || ", array[i], array[i - 1]);
            loop_array(array, size);
            i = 0;
        } else
            i += 1;
    }

}

int main(void)
{
    int array[6] = {6,5,4,3,2,1};
    int *toto = malloc(sizeof(int) * 6);

    memcpy(toto, array, sizeof(int) * 6);
    my_amazing_sorter(toto, 6);
    return 0;
}