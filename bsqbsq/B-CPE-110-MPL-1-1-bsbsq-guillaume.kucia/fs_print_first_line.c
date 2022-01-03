/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_print_first_line.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void my_putchar(char c);

void fs_print_first_line(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int fd;
    int i;
    char *buffer = malloc(sizeof(char) * (buf.st_size));
    fd = open(filepath, O_RDONLY);
    i = 0;
    read(fd, buffer, buf.st_size);

    while (buffer[i] != '\n' || buffer[i] != '\n') {
        my_putchar(buffer[i]);
        i += 1;
    }
    close(fd);
}
