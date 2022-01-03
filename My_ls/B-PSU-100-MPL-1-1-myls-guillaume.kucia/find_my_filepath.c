/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** find_my_filepath.c
*/

#include "include/my.h"

int check_my_filepath(char **av, int i)
{
    int fileRead = 0;
    struct stat buf;
    fileRead = stat(av[i], &buf);
    DIR *fd = opendir(av[i]);
    if (fd == NULL && fileRead <= (-1)) {
        return 84;
    } else {
        return 1;
    }
}

int find_my_filepath(char **av, int i)
{
    if (av[i] != NULL) {
        if (av[i][0] != '-' || (av[i][0] == '-' && (av[i][1] != 'l' &&
        av[i][1] != 'a' && av[i][1] != 'R' && av[i][1] != 'r' &&
        av[i][1] != 'd' && av[i][1] != 't')))
            return check_my_filepath(av, i);
    }
    return 84;
}

char *filepath(char **arg)
{
    while (arg[1] != NULL) {
        if (find_my_filepath(arg, 1) == 1)
            return arg[1];
        arg += 1;
    }
    return "./";
}
