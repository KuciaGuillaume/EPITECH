/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** create_command_game.c
*/

#include "my.h"
#include "var.h"
#include "engine.h"

void update_add_btn(var_t *var)
{
    static int press = 0;

    if (mouse_inside_tag("add_btn")) {
        set_shape_tag("cursor", (sfIntRect){205, 0, 173, 178}, true);
        set_shape_tag("add_btn", (sfIntRect){244, 0, 244, 29}, true);
        if (mouse_pressed(sfMouseLeft, &press)) {
            add_command(var, var->command_add);
            set_text_text(&var->text_add, "");
        }
    } else
        set_shape_tag("add_btn", (sfIntRect){0, 0, 244, 29}, true);
    if (mouse_inside_tag("add_command") && mouse_press(sfMouseLeft))
        var->actual_pad = ADD_COMMAND;
    else if (mouse_press(sfMouseLeft))
        var->actual_pad = COMMAND;
}

void create_command_game(var_t *var)
{
    create_object("add_command.png", "add_command", 10);
    create_object("add_command_btn.png", "add_btn", 9);
    set_position_tag("add_command", (V2f){600, 930});
    set_position_tag("add_btn", (V2f){611, 1010});
    set_shape_tag("add_btn", (sfIntRect){0, 0, 244, 29}, true);
}
