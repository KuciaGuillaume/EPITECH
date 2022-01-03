/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** count_lines_loop.c
*/

#include "include/my.h"
#include "unistd.h"
#include "stdlib.h"

int count_lines_loop(BSQ *file, int *i, int *char_line_ref, int *char_line)
{
    if (file->lines >= 0 && file->buffer[*i] != '\n')
            *char_line += 1;
    if (file->buffer[*i] == '\n') {
        if (file->lines == 0)
            *char_line_ref = *char_line;
        if (file->lines > 0 && *char_line_ref != *char_line)
            return 84;
        file->lines += 1;
        *char_line = 0;
    }
    *i += 1;
    return 0;
}