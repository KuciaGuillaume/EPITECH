/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** send_command.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void get_error(var_t *var, char **result)
{
    for (; !enqual(var->command, *result);)
        (*result) += 1;
}

bool hard_command(var_t *var)
{
    char *num = pastr("%g2", var->command, ' ');
    int n = 0;

    var->command = pastr("%s", var->command, ' ');
    if (num[0] != '\0')
        n = my_getnbr(num);
    if (enqual("exit", var->command))
        game_end(n);
    if (enqual("clear", var->command)) {
        var->result = my_strdup("");
        set_text_tag("result", "|> clear\n");
        set_text_position_tag("result", (V2f){600, 10});
        var->command = my_strdup("");
        return true;
    }
    return false;
}

void send_command(var_t *var)
{
    char *command = my_strcat("/home/guillaume/delivery/CSFML/bonus_42sh/"
    "42sh_csfml/exec.sh \"", var->command);
    char *get = NULL;

    if (hard_command(var))
        return;
    command = my_strcat(command, "\"");
    system(command);
    if (scan("data/command.txt", &get)) {
        if (strfind(get, "commande"))
            get_error(var, &get);
        command = my_strcat("|> ", var->initiale_command);
        command = my_strcat(command, "\n");
        var->result = my_strcat(var->result, command);
        var->result = my_strcat(var->result, get);
        set_text_tag("result", var->result);
    }
    var->command = my_strdup("");
}
