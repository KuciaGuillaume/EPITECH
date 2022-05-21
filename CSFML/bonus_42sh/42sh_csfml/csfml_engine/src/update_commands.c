/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** update_commands.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void update_on_hover(var_t *var, command_t *command)
{
    sfIntRect shape = get_shape_obj(&command->object);
    static int i = 0;

    if (mouse_inside_obj(&command->object) && !command->delete &&
        get_exits_obj(command->object)) {
        set_shape_obj(&command->object, (sfIntRect){
            446, shape.top, 446, shape.height}, true);
        set_shape_tag("cursor", (sfIntRect){205, 0, 173, 178}, true);
        set_text_color_text(&command->text, sfWhite);
        command_press(var, &i, command);
    } else if (!command->delete) {
        set_shape_obj(&command->object, (sfIntRect){
            0, shape.top, 446, shape.height}, true);
        set_text_color_text(&command->text, sfBlack);
    }
    udpate_command_delete(var, command);
}

void set_exist(command_t *copy)
{
    if (GPO(copy->object).y < 80) {
        set_exits_obj(&copy->object, false);
        set_text_visible_text(&copy->text, false);
    } else {
        set_exits_obj(&copy->object, true);
        set_text_visible_text(&copy->text, true);
    }
}

void move_all(var_t *var, float value, command_t *command, char f)
{
    command_t *copy = command;
    value *= engine.delta_time;

    for (; copy && f == 'x'; copy = copy->next) {
        SPO(copy->object, (V2f){GPO(copy->object).x + value,
        GPO(copy->object).y});
        SPTT(copy->text, (V2f){GPTT(copy->text).x + value,
        GPTT(copy->text).y});
    }
    for (; copy && f == 'y'; copy = copy->next) {
        SPO(copy->object, (V2f){GPO(copy->object).x,
        GPO(copy->object).y + value});
        SPTT(copy->text, (V2f){GPTT(copy->text).x,
        GPTT(copy->text).y + value});
        set_exist(copy);
    }
}

void update_scroll(var_t *var, command_t *command)
{
    sfVector2i c_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.window);
    int y = mouse_scroll();

    if (command == NULL || c_pos.x < GPO(command->object).x ||
    c_pos.x > GPO(command->object).x + 446)
        return;
    if (y == 1 && GPO(command->object).y < 80)
        move_all(var, 0.001, command, 'y');
    else if (y < 0 && GPO(get_last(command)->object).y + 63 > 1080)
        move_all(var, -0.001, command, 'y');
}

void update_commands(var_t *var)
{
    command_t *commands = var->commands;

    update_scroll(var, var->commands);
    for (; commands; commands = commands->next)
        update_on_hover(var, commands);
}
