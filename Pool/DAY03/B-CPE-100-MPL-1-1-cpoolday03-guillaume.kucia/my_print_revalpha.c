/*
** EPITECH PROJECT, 2021
** my_print_revalpha.c
** File description:
** Reverse my_print_alpha
*/

#include <unistd.h>


int my_print_revalpha(void) {

       
        int i = 123;
    
        while (i>97) { 

        i = i - 1;
        my_putchar(i);
        
        }
        return(0);
}





