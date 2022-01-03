/*
** EPITECH PROJECT, 2021
** DAY12
** File description:
** grepp.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../lib/my/my.h"

int multi_grep2(char **argv, int *i, char *cat_fichier, int *b)
{
    if (&cat_fichier[*i] == my_strstr(&cat_fichier[*b], argv[1])) {
        while (cat_fichier[*i] != '\n' && cat_fichier[*i] != NULL) {
        *i -= 1;
        }
        *i += 1;
        while (cat_fichier[*i] != '\n' && cat_fichier[*i] != '\0') {
            my_putchar(cat_fichier[*i]);
            *i += 1;
        }
        if (cat_fichier[*i] != '\0') {
            *i += 1;
        }
    }
    *b = *i + 1;
    my_putchar('\n');
    if (cat_fichier[*i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int multi_grep(int argc, char **argv, int ac, int *i, int *b)
{
    int fd = open(argv[ac], O_RDONLY);
    char cat_fichier[30000];
    ssize_t n = read(fd, cat_fichier, 29999);
    cat_fichier[n] = '\0';

    while (&cat_fichier[*i] != my_strstr(&cat_fichier[*b], argv[1])) {
        if (cat_fichier[*i] == '\0') {
            return 1;
        } else {
            *i += 1;
        }
    }
    multi_grep2(argv, i, cat_fichier, b);
}

int main(int argc, char **argv)
{
    int ac = 2;
    int i = 0;
    int loop = 0;
    int b = 0;

    while (ac != argc) {
        while (loop != 1) {
        loop = multi_grep(argc, argv, ac, &i, &b);
        }
        i = 0;
        loop = 0;
        b = 0;
        ac += 1;
    }

}