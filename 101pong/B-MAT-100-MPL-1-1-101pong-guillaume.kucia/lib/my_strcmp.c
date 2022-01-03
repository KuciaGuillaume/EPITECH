/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (my_strlen(s1) > my_strlen(s2)) {
        return 1;
    } else if (my_strlen(s1) < my_strlen(s2)) {
        return 2;
    }
    while (s1[i] != '\0') {
        if ((s1[i] - 48) > (s2[i] - 48)) {
            return 1;
        }
        if ((s1[i] - 48) < (s2[i] - 48)) {
            return 2;
        }
        i++;
    }
    return 0;
}
