/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** create_commands.c
*/

#include "var.h"
#include "engine.h"
#include "my.h"

void add_text(var_t *var, char *command, int y, command_t *new)
{
    sfFloatRect f_text = { 0 };
    char *modify = my_strcat(my_strcat("'", command), "'");

    new->text = create_text(modify, "commands");
    set_text_size_text(&new->text, 30);
    f_text = sfText_getGlobalBounds(new->text.text);
    set_text_position_text(new->text, (V2f){1645 - f_text.width/2, y + 12});
}

int get_y_axis(command_t *command)
{
    if (!command)
        return 80;
    for (; command->next; command = command->next);
    return get_position_obj(command->object).y + 80;
}

void add_command(var_t *var, char *command)
{
    command_t *copy = var->commands;
    command_t *new = malloc(sizeof(command_t));
    int y = get_y_axis(copy);

    new->command = my_strdup(command);
    new->next = NULL;
    new->object = create_object("commands.png", "commands", 10);
    new->delete = false;
    add_text(var, command, y, new);
    set_shape_obj(&new->object, (sfIntRect){0, 0, 446, 63}, true);
    set_position_obj(new->object, (V2f){1435, y});
    if (var->commands == NULL)
        var->commands = new;
    else {
        for (; copy->next != NULL; copy = copy->next);
        copy->next = new;
    }
}

void create_command(var_t *var)
{
    var->commands = NULL;

    add_command(var, " ");
    add_command(var, ")");
    add_command(var, "(");
    add_command(var, "|");
    // for (int i = 0; i != 30; i++)
    //     add_command(var, "ls");
    add_command(var, "(ls | cat -e) | cat -e");
    add_command(var, "(cd; ls); ls");
    add_command(var, "echo cc");
    add_command(var, "mkdir ls");
}
