/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** error_handling.c
*/

#include "include/my.h"
#include "unistd.h"
#include "stdlib.h"

int count_my_lines(struct BSQ *file)
{
    int i = 0;
    int char_line_ref = 0;
    int char_line = 0;
    file->lines = -1;

    while (i != file->size) {
        if ((count_lines_loop(file, &i, &char_line_ref, &char_line)) == 84)
            return 84;
    }
    if ((file->lines != file->nofl) || file->lines < 1)
        return 84;
    return 0;
}

int nofl(struct BSQ *file)
{
    int i = 0;
    file->nofl = 0;

    while (file->buffer[i] != '\n') {
        if (file->buffer[i] < '0' || file->buffer[i] > '9')
            return 84;
        file->nofl *= 10;
        file->nofl += file->buffer[i] - 48;
        i += 1;
    }
    return 0;
}

int read_error(struct BSQ *file)
{
    if (file->fd < 0) {
        write(2, "read failed\n", 12);
        return 84;
    }
    return 0;
}

int find_the_intruder(struct BSQ *file)
{
    int i = 0;

    while (file->buffer[i] != '\n') {
        i += 1;
    }
    while (i != file->size) {
        if (file->buffer[i] != '.' && file->buffer[i] != 'o' &&
        file->buffer[i] != '\n')
            return 84;
        i += 1;
    }
    return 0;
}

int error_handling(struct BSQ *file)
{
    if (read_error(file) == 84 || (nofl(file) == 84) ||
    (count_my_lines(file) == 84) || find_the_intruder(file) == 84) {
        write(2, "error handling\n", 15);
        return 84;
    }
    return 0;
}