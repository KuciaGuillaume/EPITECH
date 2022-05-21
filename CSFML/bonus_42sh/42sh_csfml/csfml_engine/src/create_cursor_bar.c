/*
** EPITECH PROJECT, 2021
** 42sh_csfml
** File description:
** create_cursor_bar.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void cursor_sign(var_t *var)
{
    static delta_time_t delta = {.time = 0.00, .saved = 0.00};

    if (elapsed_time_milliseconds(500, &delta.time, &delta.saved)) {
        if (get_visible_tag("CURSOR_BAR"))
            set_visible_tag("CURSOR_BAR", false);
        else
            set_visible_tag("CURSOR_BAR", true);
    }
    if (engine.event.type == sfEvtKeyPressed) {
        delta.time = 0;
        set_visible_tag("CURSOR_BAR", true);
    }
}

void cursor_bar_movement(var_t *var, V2f *target, V2f *pos)
{
    if (var->actual_pad == COMMAND) {
        *target = get_text_position_text(var->text_command);
        (*pos).y = get_text_position_text(var->text_command).y - 3;
        (*target).x += sfText_getGlobalBounds(
            var->text_command.text).width + 5;
    } else {
        (*target) = get_text_position_text(var->text_add);
        (*pos).y = get_text_position_text(var->text_add).y - 3;
        (*target).x += sfText_getGlobalBounds(var->text_add.text).width + 5;
    }
}

void update_cursor_bar(var_t *var)
{
    V2f pos = get_position_tag("CURSOR_BAR");
    float speed = 0.00001 * engine.delta_time;
    V2f target = { 0 };

    cursor_bar_movement(var, &target, &pos);
    if (pos.x < target.x) {
        speed *= (target.x - pos.x);
        set_position_tag("CURSOR_BAR", (V2f){pos.x + speed, pos.y});
    } else if (pos.x > target.x) {
        speed *= (pos.x - target.x);
        set_position_tag("CURSOR_BAR", (V2f){pos.x - speed, pos.y});
    }
    cursor_sign(var);
}

void create_cursor_bar(var_t *var)
{
    create_object("CursorBar.png", "CURSOR_BAR", 0);
    set_scale_tag("CURSOR_BAR", (V2f){1, 0.8});
}
