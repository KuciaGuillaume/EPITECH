/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_cat_500_bytes.c
*/

#include <unistd.h>
#include <fcntl.h>

int my_putstr(char const *str);

void fs_cat_500_bytes(char const *filepath)
{
    char buffer[501];
    int fd = open(filepath, O_RDONLY);
    int size = read(fd, buffer, 500);

    buffer[size] = '\0';
    my_putstr(buffer);
    close(fd);
}
