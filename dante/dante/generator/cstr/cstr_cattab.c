/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr_cattab.c
*/

#include "gen.h"
#include "cstr.h"

char **cstr_cattab(char **dest, char **tab)
{
    int *lentab1 = cstr("%d%na", dest);
    int *lentab2 = cstr("%d%na", tab);
    char **result = malloc(sizeof(char *) * (*lentab1 + *lentab2 + 1));

    for (int i = 0; i != *lentab1; i++)
        result[i] = dest[i];
    for (int e = 0; e != *lentab2; e++)
        result[*lentab1 + e] = tab[e];
    result[*lentab1 + *lentab2] = NULL;
    return result;
}

char **cstr_cattab_str(char **dest, char *str)
{
    int *lentab1 = cstr("%d%na", dest);
    int lentab2 = 1;
    char **result = malloc(sizeof(char *) * (*lentab1 + lentab2 + 1));

    for (int i = 0; i != *lentab1; i++)
        result[i] = dest[i];
    for (int e = 0; e != lentab2; e++)
        result[*lentab1 + e] = str;
    result[*lentab1 + lentab2] = NULL;
    return result;
}
