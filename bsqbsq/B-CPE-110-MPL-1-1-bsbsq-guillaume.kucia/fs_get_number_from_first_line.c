/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** fs_get_number_from_first_line.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int find_my_num(char *buffer, int i, int less, int n)
{
    if ((buffer[i] < '0' || buffer[i] > '9') && less == 1)
        less = 0;
    if (buffer[i] == '-')
        less = 1;
    if (buffer[i] >= '0' && buffer[i] <= '9' && less == 0) {
        n *= 10;
        n += buffer[i] - 48;
    }
    if (buffer[i] != '\n' && buffer[i] != '\0') {
        i += 1;
        n = find_my_num(buffer, i, less, n);
    }
    return n;
}

int fs_get_number_from_first_line(char const *filepath)
{
    struct stat buf;
    char *buffer;
    int i = 0;
    int less = 0;
    int n = 0;
    int fd = 0;

    stat(filepath, &buf);
    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    buffer[buf.st_size] = '\0';
    fd = open(filepath, O_RDONLY);
    read(fd, buffer, buf.st_size);
    n = find_my_num(buffer, i, less, n);
    close(fd);
    if (n <= 0)
        return (-1);
    return n;
}
