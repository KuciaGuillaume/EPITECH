/*
** EPITECH PROJECT, 2021
** My_ls
** File description:
** find_file_name.c
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

void pars_file_name(storage *file, int parsing)
{
    int i = 0;

    while (parsing != 0 && file->filepath[i] != '\0') {
        if (file->filepath[i] == '/')
            parsing -= 1;
        file->filepath += 1;
    }
    file->Name = file->filepath;
}

void find_file_name(storage *file)
{
    int i = 0;
    int parsing = 0;

    while (file->filepath[i] != '\0') {
        if (file->filepath[i] == '/')
            parsing += 1;
        i += 1;
    }
    if (parsing == 0)
        file->Name = file->filepath;
    else
        pars_file_name(file, parsing);
}
