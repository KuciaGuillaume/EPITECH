/*
** EPITECH PROJECT, 2021
** dante
** File description:
** error_handling.c
*/

#include "my.h"

void error_handling(int ac)
{
    if (ac != 2) {
        ac < 2 ? put("Failed(84) -> Not enough arguments\n") : 0;
        ac > 2 ? put("Failed(84) -> Too many arguments\n") : 0;
        ERROR;
    }
}
