/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** Day06 task06
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int is1 = 0;
    int is2 = 0;
    

    while (s1[is1] != '\0' && s2[is2] != '\0') {
        
        if (s1[is1] - 48 != s2[is2] - 48) {
            if (s1[is1] - 48 > s2[is2] - 48) {
                return (1);
            }
            if (s1[is1] - 48 < s2[is2] - 48) {
                return (-1);
            }
        } else {
        is1++;
        is2++;
        }
    }
    return (0);
}
