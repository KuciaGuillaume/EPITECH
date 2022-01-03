/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** print_l.c
*/

#include "include/my.h"

char *alloc_my_permits(struct stat *buf, int *i, char *permits)
{
    if (buf->st_nlink < 10)
        *i = 3;
    if (buf->st_nlink < 100 && buf->st_nlink > 9)
        *i = 4;
    if (buf->st_nlink < 1000 && buf->st_nlink > 99)
        *i = 5;
    permits = malloc(sizeof(char) * (12 + *i));
    return permits;
}

char *set_my_hard_link(struct stat *buf, char *permits, int i)
{
    permits[10] = ' ';
    permits[10 + i - 2] = ((buf->st_nlink) % 10) + 48;
    if (buf->st_nlink > 9)
        permits[10 + i - 3] = (((buf->st_nlink) % 100) / 10) + 48;
    if (buf->st_nlink > 99)
        permits[10 + i - 4] = (((buf->st_nlink) / 100) % 10) + 48;
    permits[10 + (i - 1)] = ' ';
    permits[11 + (i - 1)] = '\0';
    return permits;
}

char *permissions(char *filename, char *permits)
{
    struct stat buf;
    int i = 0;

    stat(filename, &buf);
    permits = alloc_my_permits(&buf, &i, permits);
    if ((S_ISDIR(buf.st_mode) > 0))
        permits[0] = 'd';
    else
        permits[0] = '-';
    permits = find_permissions(permits, &buf);
    permits = set_my_hard_link(&buf, permits, i);
    return permits;
}

void print_l(option_t *opt, char **av)
{
    storage_t storage;
    storage.i = 0;
    storage.total = 0;
    struct stat file;
    storage.long_result = "\0";

    if (opt->n_dest_f != 0)
        my_printf("\n");
    storage.directory = filepath(av);
    char *test = my_strdup(storage.directory);

    while (parse_my_file(storage.directory, storage.i, opt) != NULL) {
        storage.filename = parse_my_file(storage.directory, storage.i, opt);
        if (opt->d != 1 || (opt->d == 1 && storage.filename[0] == '.' &&
        storage.filename[1] == '\0')) {
            set_loop_l(&storage, &file, test, opt);
            if (my_strcmp(storage.filename, "hide") != 0) {
                if (storage.long_result[0] == '\0')
                    storage.long_result = my_strcat(storage.long_result, storage.result);
                else
                    storage.long_result = my_strcat(my_strcat(storage.long_result, "\n"), storage.result);
            }
        }
        storage.i += 1;
    }
    if (opt->passed <= 1) {
        if (opt->d != 1 && opt->passed_file == 0)
            my_printf("total %d\n", storage.total);
        my_printf("%s\n", storage.long_result);
    } else {
        my_printf("%s:\n", storage.directory);
        if (opt->d != 1)
            my_printf("total %d\n", storage.total);
        if (opt->is_end != 1) {
            my_printf("%s\n\n", storage.long_result);
            opt->is_end -= 1;
        } else
            my_printf("%s\n", storage.long_result);
    }
}