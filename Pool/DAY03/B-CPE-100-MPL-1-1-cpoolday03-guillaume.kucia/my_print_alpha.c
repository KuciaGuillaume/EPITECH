/*
** EPITECH PROJECT, 2021
** my_print_alpha.c
** File description:
** Ecrire une fonction qui, commençant par a, affiche l'alphabet minuscule dans l'ordre croissant, sur une seule ligne.
*/

#include <unistd.h>



int my_print_alpha(void) {

       
        int i = 96;
    
        while (i<122) { 

        i = i + 1;
        my_putchar(i);
        
        }
        return(0);
}







   
      
