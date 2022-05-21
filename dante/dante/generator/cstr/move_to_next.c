/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** move_to_next.c
*/

#include "cstr.h"

char *move_to_next(char *str, char pipe)
{
    for (; str[0] != pipe && str[0] != '\0'; str++);
    for (; str[0] == pipe && str[0] != '\0'; str++);
    return str;
}
