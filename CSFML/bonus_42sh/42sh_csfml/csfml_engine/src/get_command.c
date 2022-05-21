/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** get_command.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

command_t *get_last(command_t *command)
{
    command_t *copy = command;

    for (; copy->next != NULL; copy = copy->next);
    return (copy);
}
