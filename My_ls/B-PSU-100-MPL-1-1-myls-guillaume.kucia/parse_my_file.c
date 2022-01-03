/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** parse_my_file.c
*/

#include "include/my.h"

struct dirent *find_loop(int *t, int *i, DIR *fd)
{
    struct dirent *file;
    while (*t <= *i) {
        file = readdir(fd);
        *t += 1;
    }
    return file;
}

char *find_my_filename(char *directory, option_t *opt)
{
    int i = 0;
    int slash = 0;
    opt->passed_file += 1;

    while (directory[i] != '\0') {
        if (directory[i] == '/')
            slash += 1;
        i += 1;
    }
    while (slash != 0) {
        if (directory[0] == '/')
            slash -= 1;
        directory += 1;
    }
    return directory;
}

char *cut_my_directory(char *directory)
{
    int i = 0;
    int slash = 0;
    char *result;

    while (directory[i] != '\0') {
        if (directory[i] == '/')
            slash += 1;
        i += 1;
    }
    i = 0;
    while (slash != 0) {
        if (directory[i] == '/')
            slash -= 1;
        i += 1;
    }
    directory[i] = '\0';
    result = malloc(sizeof(char) * (my_strlen(directory)));
    result = my_strdup(directory);
    return result;
}

char *parse_my_file(char *directory, int i, option_t *opt)
{
    int t = 0;
    int readfile;
    int hide = 1;
    struct dirent *file;
    char *filename;
    DIR *fd = opendir(directory);
    struct stat buf;
    readfile = stat(directory, &buf);

    if (opt->a == 1)
        hide = 0;
    if (fd == NULL && readfile <= -1) {
        return NULL;
    }
    if (fd != NULL) {
        file = find_loop(&t, &i, fd);
    } else if (readfile > (-1) && opt->passed_file < 2) {
        return find_my_filename(directory, opt);
    } else
        return NULL;
    if (file != NULL) {
        filename = my_strdup(file->d_name);
        closedir(fd);
        if (hide == 0 || (hide == 1 && filename[0] != '.'))
            return filename;
        else
            return "hide";
    }
    return NULL;
}