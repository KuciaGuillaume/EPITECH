/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** set_loop_l.c
*/

#include "include/my.h"

char *get_my_char_2(char *number, int n, int i)
{
    if (n >= 1000)
        number[i - 3] = (((n) / 1000) % 10) + 48;
    if (n >= 10000)
        number[i - 4] = (((n) / 10000) % 10) + 48;
    if (n >= 100000)
        number[i - 5] = (((n) / 100000) % 10) + 48;
    if (n >= 1000000)
        number[i - 6] = (((n) / 1000000) % 10) + 48;
    if (n >= 10000000)
        number[i - 7] = (((n) / 10000000) % 10) + 48;
    if (n >= 100000000)
        number[i - 8] = (((n) / 100000000) % 10) + 48;
    return number;
}

char *get_my_char(int n)
{
    int i = 0;
    int e = n;
    char *number;

    while (e > 10) {
        e /= 10;
        i += 1;
    }
    number = malloc(sizeof(char) * (i + 2));
    number[i + 1] = '\0';
    number[i] = (n % 10) + 48;
    if (n >= 10)
        number[i - 1] = (((n) % 100) / 10) + 48;
    if (n >= 100)
        number[i - 2] = (((n) / 100) % 10) + 48;
    return get_my_char_2(number, n, i);
}

void set_loop_2(storage_t *storage, char *test, option_t *opt)
{
    if (opt->d == 1 || opt->passed_file != 0)
        storage->filename = my_strdup(storage->directory);
    storage->result = malloc(sizeof(char) * ((my_strlen(storage->permits) +
    my_strlen(storage->pws->pw_name) + my_strlen(storage->pws_gid->pw_name) +
    (my_strlen(storage->filename)) + (my_strlen(storage->allocate_space)) +
    my_strlen(storage->atime))));
    storage->result = (my_strcat(my_strcat(storage->permits,
    my_strcat(storage->pws->pw_name, " ")),
    my_strcat(my_strcat(storage->pws_gid->pw_name, " "),
    my_strcat(my_strcat(storage->allocate_space, " "),
    my_strcat(my_strcat(storage->atime, " "), storage->filename)))));
    storage->directory = my_strdup(test);
}

void set_loop_l(storage_t *storage, struct stat *file, char *test, option_t *opt)
{
    if (my_strcmp(storage->filename, "hide") != 0) {
        if (opt->passed_file == 0) {
            storage->permits = permissions(my_strcat(my_strcat(storage->directory,
            "/"), storage->filename), storage->permits);
            stat(my_strcat(my_strcat(storage->directory, "/"),
            storage->filename), file);
        } else {
            storage->permits = permissions(storage->directory, storage->permits);
            stat(storage->directory, file);
        }
        storage->pws = getpwuid(file->st_uid);
        storage->pws_gid = getpwuid(file->st_gid);
        storage->allocate_space = get_my_char(file->st_size);
        storage->atime = ctime(&file->st_mtime);
        storage->atime[my_strlen(storage->atime) - 1] = '\0';
        storage->atime += 4;
        storage->total += file->st_blocks / 2;
        set_loop_2(storage, test, opt);
    }
}