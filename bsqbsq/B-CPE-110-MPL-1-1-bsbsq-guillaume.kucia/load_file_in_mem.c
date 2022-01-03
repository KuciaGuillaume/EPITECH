/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** load_file_in_mem.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    char *buffer = malloc(sizeof(char) * (buf.st_size));
    int fd = open(filepath, O_RDONLY);
    int i = read(fd, buffer, buf.st_size);
    return buffer;
}
