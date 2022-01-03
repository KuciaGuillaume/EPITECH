/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** Day06 task06
*/

#include <unistd.h>

int calcule(int n1, int n, int n2)
{
    while (n1 != n) {
    	n2 = n2 + 1;
    }
    return n2;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int is1 = 0;
    int is2 = 0;
    int n1 = 0;
    int n2 = calcule(n1, n, n2);

    while (s1[is1] != s1[n2] && s2[is2] != s2[n2]) {
        if (s1[is1] - 48 != s2[is2] - 48) {
            if (s1[is1] - 48 > s2[is2] - 48) {
                return (1);
            } else {
                return (-1);
            }
        } else {
            is1 = is1 + 1;
            is2 = is2 + 1;
        }
    }
    return (0);
}
