/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** engine.h
*/

#include "engine.h"
#include "my.h"

#ifndef VAR_H
    #define VAR_H

enum pad {
    COMMAND,
    ADD_COMMAND,
};

typedef struct command_s {
    obj_t object;
    text_t text;
    char *command;
    bool delete;
    struct command_s *next;
} command_t;

struct var_s
{
    command_t *commands;
    char *command;
    char **env;
    char *result;
    text_t text_command;
    bool deleted;
    char *command_add;
    int actual_pad;
    char *initiale_command;
    text_t text_add;
};
typedef struct var_s var_t;

void create(var_t *var);
void update(var_t *var);
void engine_is_open(int *start, var_t *var);
command_t *get_last(command_t *command);
void input(var_t *var, char **command);
void send_command(var_t *var);
bool get_altgr(var_t *var, float dc, bool *altgr);
char get_special_altgr(float d, char c, bool altgr);
void create_cursor_bar(var_t *var);
void update_cursor_bar(var_t *var);
void udpate_command_delete(var_t *var, command_t *command);
void create_command_game(var_t *var);
void update_add_btn(var_t *var);
void create_text_add_command(var_t *var);
void update_text_add_command(var_t *var);
void command_press(var_t *var, int *i, command_t * command);

void create_command(var_t *var);
void update_commands(var_t *var);
void add_command(var_t *var, char *command);
void repair_str(var_t *var);

#endif // END //
