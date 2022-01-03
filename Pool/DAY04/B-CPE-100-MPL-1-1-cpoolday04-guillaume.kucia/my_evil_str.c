/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** DAY04 task04
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    char mot;
    int a;
    int b;
    
    a = my_strlen(str) - 1;
    b = 0;

    while (b < a)
    {
        mot = str[b]; 
        str[b] = str[a];
        str[a] = mot;      
        b = b + 1;
        a = a - 1;
    }
    return(str);           
}