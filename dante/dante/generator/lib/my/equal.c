/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** my_equal.c
*/

#include "gen.h"

bool equal(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

bool nequal(char *s1, char *s2, int n)
{
    if ((s1[0] == '\0' && s2[0] != '\0') ||
    (s1[0] != '\0' && s2[0] == '\0'))
        return false;
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return false;
    for (int i = 0; s1[i] && i != n; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

bool enqual(char *s1, char *s2)
{
    int n = my_strlen(s1);

    if ((s1[0] == '\0' && s2[0] != '\0') ||
    (s1[0] != '\0' && s2[0] == '\0'))
        return false;
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return false;
    for (int i = 0; s1[i] && i != n; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}
