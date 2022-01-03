/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_cat_x_bytes.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int my_putstr(char const *str);

void fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer = malloc(sizeof(char) * (x + 1));
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, x);
    buffer[x] = '\0';
    my_putstr(buffer);
    free(buffer);
    close(fd);
}
