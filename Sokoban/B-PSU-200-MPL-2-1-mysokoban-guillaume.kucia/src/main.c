/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "my.h"

void before_closed(sokoban_t *sokoban)
{
    clear();
    display_sokoban(sokoban);
    refresh();
    endwin();
}

int calc_objectives(char *original_map)
{
    int objectives = 0;

    for (int i = 0; original_map[i] != '\0'; i++) {
        if (original_map[i] == 'O')
            objectives++;
    }
    return objectives;
}

int main(int ac, char **av)
{
    sokoban_t sokoban;
    int fd = 0;

    fd = open_map(ac, av, &sokoban);
    sokoban.objectives = calc_objectives(sokoban.original_map);
    if (fd == 84)
        return 84;
    if (fd != 1)
        return my_sokoban(&sokoban);
    return 0;
}
