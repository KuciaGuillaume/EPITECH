/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** error_checking.c
*/

#include "my.h"

int print_help(void)
{
    put(""
    "USAGE\n"
    "     ./my_sokoban map\n"
    "DESCRIPTION\n"
    "     map file representing the warehouse map, containing, '#'"
    " for walls, \n"
    "         'P' for the player, 'X' for boxes and '0'"
    " for storage locations.\n");
    return 1;
}

int open_map(int ac, char **av, sokoban_t *sokoban)
{
    if (ac > 2) {
        put("Error handling: too many arguments\n");
        return 84;
    } else if (ac < 2) {
        put("Error handling: not enough arguments\n");
        return 84;
    }
    if (equal("-h", av[1]) == true)
        return print_help();
    if (scan(av[1], &sokoban->map) == false)
        return 84;
    if (allowed(sokoban->map, " \n#XOP\0") == false) {
        put("Error handling: invalid character\n");
        return 84;
    }
    sokoban->original_map = my_strdup(sokoban->map);
    return 0;
}
