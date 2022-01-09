/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** read_write_score.c
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void read_write_score(window_t *window)
{
    char *map_score = "0";
    int fd = 0;
    int i = 0;

    fd = open(window->filepath_score, O_RDONLY | O_CREAT);
    map_score = my_calloc(map_score, 100);
    read(fd, map_score, 100);
    for (; (map_score[i] >= '0' && map_score[i] <= '9'); i += 1);
    map_score[i] = '\0';
    if (window->score.n > my_getnbr(map_score)) {
        i = 0;
        fd = open(window->filepath_score, O_WRONLY | O_TRUNC);
        write(fd, my_itoa(window->score.n, 0), size_of_int(window->score.n));
        close(fd);
        fd = open(window->filepath_score, O_RDONLY);
        map_score = my_calloc(map_score, 100);
        read(fd, map_score, 100);
        for (; (map_score[i] >= '0' && map_score[i] <= '9'); i += 1);
        map_score[i] = '\0';
    }
    window->score.best_score = my_getnbr(map_score);
}
