/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void all_input(var_t *var)
{
    if (key_pressed(sfKeyEscape))
        game_end(0);
    if (var->actual_pad == COMMAND)
        input(var, &var->command);
    if (var->actual_pad == ADD_COMMAND)
        input(var, &var->command_add);
    if (key_pressed(sfKeyEnter) && var->actual_pad == COMMAND) {
        repair_str(var);
        send_command(var);
    }
}

void update_cursor(var_t *var)
{
    sfVector2i c_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.window);

    set_shape_tag("cursor", (sfIntRect){0, 0, 173, 178}, true);
    SPT("cursor", (V2f){c_pos.x, c_pos.y});
}

void update_text(var_t *var)
{
    V2f text_p = get_text_position_tag("result");
    float speed = 0.0001;
    sfFloatRect global = sfText_getGlobalBounds(
        get_text_tag("result"));

    set_text_tag("COMMAND", var->command);
    if (text_p.y + global.height > 700) {
        speed = ((text_p.y + global.height) - 500) / 1000000;
        set_text_position_tag("result", (V2f){text_p.x,
        text_p.y - (speed * DELTA)});
    }

}

void update(var_t *var)
{
    all_input(var);
    update_cursor(var);
    update_commands(var);
    update_text(var);
    update_cursor_bar(var);
    update_add_btn(var);
    update_text_add_command(var);
}
