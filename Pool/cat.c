/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** cat.c
*/

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

void my_putchar(char c);

int my_putstr(char const *str);

int main(int argc, char **argv) {
    int err = 0;
    int fd = 2;
    int ac = 1;

    while (ac != argc) {
        fd = open(argv[ac], O_RDONLY | O_CREAT, 0644);
        ac += 1;

        char cat_fichier[30000];
        ssize_t n = read(fd, cat_fichier, 29999);
        cat_fichier[n] = '\0';

        my_putstr(cat_fichier);

        err = close(fd);
    }

    return 0;
}