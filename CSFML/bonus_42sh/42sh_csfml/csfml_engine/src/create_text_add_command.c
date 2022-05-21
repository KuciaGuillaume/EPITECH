/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** create_text_add_command.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void update_text_add_command(var_t *var)
{
    set_text_tag("command_add", var->command_add);
}

void create_text_add_command(var_t *var)
{
    var->text_add = create_text(var->command_add, "command_add");
    set_text_size_tag("command_add", 15);
    set_text_color_tag("command_add", sfWhite);
    set_text_position_tag("command_add", (V2f){620, 958});
}
