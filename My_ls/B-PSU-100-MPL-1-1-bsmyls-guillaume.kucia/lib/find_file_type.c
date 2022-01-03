/*
** EPITECH PROJECT, 2021
** My_ls
** File description:
** find_file_type.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <errno.h>
#include <ncurses.h>
#include "../include/my.h"
#include <fcntl.h>

void find_file_type(storage *file, struct stat *buf)
{
    if (S_ISREG(buf->st_mode) == 1)
        file->Type = 'r';
    if (S_ISDIR(buf->st_mode) == 1)
        file->Type = 'd';
    if (S_ISCHR(buf->st_mode) == 1)
        file->Type = 'c';
    if (S_ISBLK(buf->st_mode) == 1)
        file->Type = 'b';
    if (S_ISFIFO(buf->st_mode) == 1)
        file->Type = 'f';
    if (S_ISLNK(buf->st_mode) == 1)
        file->Type = 'l';
    if (S_ISSOCK(buf->st_mode) == 1)
        file->Type = 's';
}