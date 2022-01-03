/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myls-guillaume.kucia
** File description:
** find_permissions.c
*/

#include "include/my.h"

char *find_permissions(char *permits, struct stat *buf)
{
    ((buf->st_mode & S_IRUSR) ? (permits[1] = 'r') : (permits[1] = '-'));
    ((buf->st_mode & S_IWUSR) ? (permits[2] = 'w') : (permits[2] = '-'));
    ((buf->st_mode & S_IXUSR) ? (permits[3] = 'x') : (permits[3] = '-'));
    ((buf->st_mode & S_IRGRP) ? (permits[4] = 'r') : (permits[4] = '-'));
    ((buf->st_mode & S_IWGRP) ? (permits[5] = 'w') : (permits[5] = '-'));
    ((buf->st_mode & S_IXGRP) ? (permits[6] = 'x') : (permits[6] = '-'));
    ((buf->st_mode & S_IROTH) ? (permits[7] = 'r') : (permits[7] = '-'));
    ((buf->st_mode & S_IWOTH) ? (permits[8] = 'w') : (permits[8] = '-'));
    ((buf->st_mode & S_IXOTH) ? (permits[9] = 'x') : (permits[9] = '-'));
    return permits;
}
