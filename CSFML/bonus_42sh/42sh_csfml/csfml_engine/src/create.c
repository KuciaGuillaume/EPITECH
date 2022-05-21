/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_mouse(var_t *var)
{
    create_object("cursor.png", "cursor", 0);
    SCT("cursor", (V2f){0.2, 0.2});
    SST("cursor", (sfIntRect){0, 0, 173, 178}, true);
    sfRenderWindow_setMouseCursorVisible(engine.win_settings.window, sfFalse);
}

void setup(var_t *var)
{
    set_background("background.png", false);
    var->deleted = false;
    var->actual_pad = COMMAND;
    var->command_add = my_strdup("");
}

void create_enter(var_t *var)
{
    char pwd[1024];
    char *path = my_strdup("");
    text_t text = { 0 };

    var->command = my_strdup("");
    getcwd(pwd, sizeof(pwd));
    path = my_strcat(pwd, " -> ");
    text = create_text(path, "ENTER");
    var->text_command = create_text(var->command, "COMMAND");
    set_text_color_tag("ENTER", sfWhite);
    set_text_color_tag("COMMAND", sfWhite);
    set_text_position_tag("ENTER", (V2f){590, 858});
    set_text_position_tag("COMMAND", (V2f){
        590 + sfText_getGlobalBounds(text.text).width, 858});
}

void create_result(var_t *var)
{
    var->result = my_strdup("");
    create_text("|>", "result");
    set_text_position_tag("result", (V2f){600, 10});
    set_text_color_tag("result", sfWhite);
}

void create(var_t *var)
{
    create_mouse(var);
    setup(var);
    create_command(var);
    create_enter(var);
    create_result(var);
    create_cursor_bar(var);
    create_command_game(var);
    create_text_add_command(var);
}
