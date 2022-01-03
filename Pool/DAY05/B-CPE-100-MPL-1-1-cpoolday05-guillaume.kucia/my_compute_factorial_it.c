/*
** EPITECH PROJECT, 2021
** my_compute_factorial.c
** File description:
** Day05 task01
*/

#include <unistd.h>

int my_compute_factorial_it(int nb)
{
    if (nb >= 13) {
        return (0) ;
    }
    
    if (nb <= 0) {
        return nb == 0 ? 1 : 0 ;
    }

    int n = 1 ;
    int i = 2 ;

    while(i <= nb) {
        n = i + n ;
        i = i + 1 ;
    }

    return (n);
}
