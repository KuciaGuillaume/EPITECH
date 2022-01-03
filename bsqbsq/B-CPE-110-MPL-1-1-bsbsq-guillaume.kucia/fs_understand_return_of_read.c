/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_understand_return_of_read.c
*/

#include <unistd.h>
#include <fcntl.h>

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int i = read(fd, buffer, size);

    if (i == (-1))
        write(2, "read failed\n", 12);
    if (i == 0)
        write(1, "read has nothing more to read\n", 30);
    if (i < size && i != (-1) && i != 0)
        write(1, "read didn't complete the entire buffer\n", 39);
    if (i == size)
        write(1, "read completed the entire buffer\n", 33);
}
