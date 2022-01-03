/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i += 1;
    }
    return i;
}
