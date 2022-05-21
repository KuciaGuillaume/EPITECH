/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** repair_str.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void repair_str(var_t *var)
{
    int size = charnfind(var->command, '"') + my_strlen(var->command);
    char *result = malloc(sizeof(char) * (size + 1));
    int i = 0;

    result[size] = '\0';
    var->initiale_command = my_strdup(var->command);
    for (int e = 0; var->command[e]; e++, i++) {
        if (var->command[e] == '"') {
            result[i++] = '\\';
            result[i] = '"';
        } else
            result[i] = var->command[e];
    }
    var->command = my_strdup(result);
}
