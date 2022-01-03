/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** Day06 task08
*/

#include <unistd.h>

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        } else {
            str[i] = str[i];
        }
        i++;
    }
    return (str);
}
