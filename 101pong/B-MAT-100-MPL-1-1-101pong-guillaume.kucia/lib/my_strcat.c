/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strcat.c
*/

//set _ "-";

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_strcat(char *str, char str2)
{
    int i = 1;
    char *less = malloc((sizeof(char) * (my_strlen(str))) + 1);

    less[0] = str2;
    while (i != (my_strlen(str) + 1)) {
        less[i] = str[ i- 1];
        i += 1;
    }
    less[i + 1] = '\0';
    return less;
}
