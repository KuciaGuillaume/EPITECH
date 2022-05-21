/*
** EPITECH PROJECT, 2021
** src
** File description:
** solver.c
*/

#include "my.h"

void assist(void)
{
    put(""
    "USAGE\n"
    "     ./solver [maze.txt]\n"
    "DESCRIPTION\n"
    "     maze.txt: Allowed characters are '*' and 'X'.\n"
    "     *: Represents a path.\n"
    "     X: Represents a wall.\n");
    Close;
}

int main(int ac, char **av)
{
    char *maze;
    int full;

    error_handling(ac);
    if (strcmp(av[1], "-h") == 0)
        assist();
    else if (!scan(av[1], &maze, &full))
        exit_msg("Unable to find or open file.\n", 84);
    if (!allowed(maze, "X*\n"))
        exit_msg("The data file contains illegal characters.\nPlease fill in"
        " a file containing only these characters:\n"
        "-*\n-X\n", 84);
    maze_solver(maze, full);
    return 0;
}
