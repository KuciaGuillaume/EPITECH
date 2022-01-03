/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** DAY05 task03
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_power_it(int nb, int p)
{
       long int result;
       int task;
       result = nb;
       task = p - 1;

       if (task < 0) {
              return 0;
       }

       while (task != 0) {
              result = result * nb ;
              task = task - 1;
       }

       if (result < 2147483647 && result > -2147483647) {
       return result;
       } else {
       return 0;
       }
}
