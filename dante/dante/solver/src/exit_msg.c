/*
** EPITECH PROJECT, 2021
** dante
** File description:
** exit_msg.c
*/

#include "my.h"

void exit_msg(char *msg, int value)
{
    put("%s", msg);
    exit (value);
}
