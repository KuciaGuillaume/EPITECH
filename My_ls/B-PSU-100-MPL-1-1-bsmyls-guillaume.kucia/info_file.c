/*
** EPITECH PROJECT, 2021
** My_ls
** File description:
** my_ls.c
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
#include <features.h>
#include <sys/sysmacros.h>
#include "include/my.h"
#include <fcntl.h>

void write_my_ls(storage *file, struct stat *buf)
{
    my_printf("Name: %s\n", file->Name);
    my_printf("Type: %c\n", file->Type);
    my_printf("Inode: %ld\n", file->Inode);
    my_printf("Hard Link: %d\n", file->Hard_Link);
    my_printf("Size: %ld\n", file->Size);
    my_printf("Allocated space: %ld\n", file->Allocatte_space);
    if (((S_ISCHR(buf->st_mode) == (S_ISBLK(buf->st_mode))))) {
        my_printf("Minor: N/A\n");
        my_printf("Major: N/A\n");
    } else {
        my_printf("Minor: %d\n", file->Minor);
        my_printf("Major: %d\n", file->Major);
    }
    my_printf("UID: %d\n", file->UID);
    my_printf("GID: %d\n", file->GID);

}

int info_file(int argc, char **argv, struct stat *buf, storage *file)
{
    if (stat(argv[argc - 1], buf) == (-1))
        return 84;
    file->filepath = argv[argc - 1];
    find_file_name(file);
    find_file_type(file, buf);
    file->Inode = buf->st_ino;
    file->Hard_Link = buf->st_nlink;
    file->Size = buf->st_size;
    file->Allocatte_space = buf->st_blocks * buf->st_blksize;
    file->Major = major(buf->st_dev);
    file->Minor = minor(buf->st_dev);
    file->UID = buf->st_uid;
    file->GID = buf->st_gid;
    return 0;
}

int main(int argc, char **argv)
{
    struct stat buf;
    storage file;

    if (info_file(argc, argv, &buf, &file) == 84) {
        write(2, "File not found\n", 15);
        return 84;
    }
    write_my_ls(&file, &buf);
    return 0;
}
