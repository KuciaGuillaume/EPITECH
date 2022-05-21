/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** command_press.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void command_press(var_t *var, int *i, command_t * command)
{
    if (mouse_pressed(sfMouseLeft, i) && !var->deleted &&
    (my_strlen(var->command) + my_strlen(command->command) < 39)) {
        if (var->actual_pad == COMMAND)
            var->command = my_strcat(var->command, command->command);
        else
            var->command_add = my_strcat(var->command_add, command->command);
    } else
        var->deleted = false;
}
