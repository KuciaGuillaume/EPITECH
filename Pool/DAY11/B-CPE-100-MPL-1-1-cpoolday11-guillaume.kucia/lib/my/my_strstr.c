/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** Day06 task05
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int f = 0;
    int m = 0;

    while (str[i] != '\0') {
        if (to_find[f] == str[i] && (str[i-1] == to_find[f-1] || str[i] == to_find[0])) {
            f++;
            if (str[i] == to_find[0]) {
                m = i;
            }
            if (to_find[f] == '\0') {
                return &str[m];
            }
        }
        i++;
    }
    return "";
}
