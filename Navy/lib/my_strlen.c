/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** DAY04 Task03
*/

#include <unistd.h>

#include <stdio.h>

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}
