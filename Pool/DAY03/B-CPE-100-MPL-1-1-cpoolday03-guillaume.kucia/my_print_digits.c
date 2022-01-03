/*
** EPITECH PROJECT, 2021
** my_print_digits.c
** File description:
** Ecrire tout les chiffres dans l'ordre croissant sur une seule ligne.
*/

#include <unistd.h>


int my_print_digits(void) {

       
        int i = 47;
    
        while (i<57) { 

        i = i + 1;
        my_putchar(i);
        
        }
        return(0);
}





