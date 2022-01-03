/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** Day06 task09
*/

#include <unistd.h>

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        } else {
            str[i] = str[i];
        }

        i++;
    }
    return (str);
}
