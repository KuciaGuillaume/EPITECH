/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** scan.c
*/

#include "my.h"

bool scan(char *filepath, char **buffer, int *full)
{
    struct stat scan;
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        return false;
    stat(filepath, &scan);
    (*buffer) = malloc(sizeof(char) * scan.st_size + 1);
    (*buffer)[scan.st_size] = '\0';
    *full = scan.st_size;
    if (read(fd, (*buffer), scan.st_size) < 0) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
