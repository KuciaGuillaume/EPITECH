/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** update_command_delete.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void replace_all(var_t *var, command_t *command)
{
    command_t *copy = command;
    V2f pos = {0, 0};

    for (; copy; copy = copy->next) {
        pos = get_position_obj(copy->object);
        set_position_obj(copy->object, (V2f){pos.x, pos.y - 80});
        pos = get_text_position_text(copy->text);
        set_text_position_text(copy->text, (V2f){pos.x, pos.y - 80});
    }
}

void delete_command(var_t *var, command_t *command)
{
    command_t *copy = var->commands;
    command_t *previous = NULL;

    for (; copy->object.id != command->object.id; copy = copy->next)
        previous = copy;
    if (previous == NULL) {
        var->commands = var->commands->next;
        destroy_object(command->object.id);
        destroy_text(&command->text);
    } else {
        previous->next = copy->next;
        destroy_object(command->object.id);
        destroy_text(&command->text);
    }
    replace_all(var, command->next);
    command = NULL;
    var->deleted = true;
}

void add_delete(var_t *var, command_t *command)
{
    static int i = 0;

    if (mouse_inside_obj(&command->object) && mouse_pressed(sfMouseRight, &i)) {
        set_shape_obj(&command->object, (sfIntRect){892, 0, 446, 63}, true);
        command->delete = true;
    } else if (!mouse_inside_obj(&command->object))
        command->delete = false;
    if (!command->delete)
        set_text_visible_text(&command->text, true);
    else {
        set_text_visible_text(&command->text, false);
        if (mouse_press(sfMouseLeft))
            delete_command(var, command);
    }
}

void udpate_command_delete(var_t *var, command_t *command)
{
    for (; command; command = command->next)
        add_delete(var, command);
}
