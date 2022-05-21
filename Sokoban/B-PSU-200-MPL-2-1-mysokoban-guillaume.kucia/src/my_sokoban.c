/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** my_sokoban.c
*/

#include "my.h"

void reattribute_map(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->original_map[i] != '\0'; i++) {
        if (sokoban->original_map[i] == 'O' && sokoban->map[i] == ' ')
            sokoban->map[i] = sokoban->original_map[i];
    }
}

void get_command(int *fd, sokoban_t *sokoban)
{
    if (*fd == KEY_RIGHT)
        move_this_x(sokoban, 'P', 1);
    if (*fd == KEY_LEFT)
        move_this_x(sokoban, 'P', -1);
    if (*fd == KEY_UP)
        move_this_y(sokoban, 'P', 1);
    if (*fd == KEY_DOWN)
        move_this_y(sokoban, 'P', -1);
    if (*fd == 32)
        sokoban->map = my_strdup(sokoban->original_map);
}

int scan_map(sokoban_t *sokoban)
{
    int objectives = sokoban->objectives;
    for (int i = 0; sokoban->original_map[i] != '\0'; i++) {
        if (sokoban->original_map[i] == 'O' && sokoban->map[i] == 'X')
            objectives--;
    }
    if (move_possible(sokoban->map) == false)
        return 1;
    if (objectives == 0)
        return 0;
    return 65;
}

void display_sokoban(sokoban_t *sokoban)
{
    int ymax = 0;
    int xmax = 0;

    getmaxyx(stdscr, ymax, xmax);
    if (xmax > calc_line(sokoban->map) && ymax > calc_col(sokoban->map)) {
        move(0, 0);
        printw(sokoban->map);
    } else {
        move(ymax/2, xmax/2 - 9);
        printw("Elarge the terminal");
    }
}

int my_sokoban(sokoban_t *sokoban)
{
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    int fd = 0;

    while (1) {
        clear();
        display_sokoban(sokoban);
        fd = getch();
        get_command(&fd, sokoban);
        reattribute_map(sokoban);
        fd = scan_map(sokoban);
        if (fd != 65) {
            before_closed(sokoban);
            return fd;
        }
    }
    endwin();
    return 0;
}
