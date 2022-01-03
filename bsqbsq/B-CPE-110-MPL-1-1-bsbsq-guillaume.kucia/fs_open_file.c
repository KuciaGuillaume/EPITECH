/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_open_file.c
*/

#include <unistd.h>
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == (-1)) {
        write(2, "FAILURE\n", 8);
        return fd;
    }
    write(1, "SUCCESS\n", 8);
    return fd;
}
