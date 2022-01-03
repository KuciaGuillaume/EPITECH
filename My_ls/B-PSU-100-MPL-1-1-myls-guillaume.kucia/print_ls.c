/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** print_ls.c
*/

#include "include/my.h"

void print_file_name(char *filepath)
{
    my_printf("%s\n", filepath);
}

void print_ls_d(struct dirent *file, char *filepath)
{
    if (file->d_name[0] == '.' && file->d_name[1] == '\0')
        my_printf("%s\n", filepath);
}

void print_directory(DIR *fd, struct dirent *file, option_t *opt, char *filepath)
{
    file = readdir(fd);
    while (file != NULL) {
        if (file->d_name[0] != '.' && opt->d != 1)
            my_printf("%s\n", file->d_name);
        if (opt->d == 1)
            print_ls_d(file, filepath);
        file = readdir(fd);
    }
}

void print_ls(char *filepath, option_t *opt)
{
    struct dirent file;
    DIR *fd = opendir(filepath);

    if (fd == NULL) {
        print_file_name(filepath);
    } else {
        print_directory(fd, &file, opt, filepath);
    }
}