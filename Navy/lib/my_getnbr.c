/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nathan.catalan
** File description:
** my_getnbr
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int my_getnbr(char const *str)
{
    int a = 0;
    int cpt = 0;
    long int result = 0;

    while (str[a] == '-' || str[a] == '+') {
        if (str[a] == '-') {
            cpt = cpt + 1;
            a = a + 1;
        } else
            a = a + 1;
    }
    while (str[a] >= 48 && str[a] <= 57 && str[a] != '\0') {
        result = result * 10  + (str[a] - '0');
        if (result > 2147483648 || result < -2147483648)
            return 0;

        a = a + 1;
    }
    if (cpt % 2 == 1)
        result = result * -1;
    return result;
}
