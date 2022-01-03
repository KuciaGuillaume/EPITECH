/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
** File description:
** my.h
*/

#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#ifndef HEADERS
    #define HEADERS
typedef struct BSQ BSQ;
struct BSQ
{
    char *buffer;
    int **map_array;
    int fd;
    int size;
    int nofl;
    int lines;
    int columns;
    int y;
    int x;
    int smaller;
    int case_r;

    int biggest_x;
    int biggest_y;
    int biggest_size;
};
int my_getnbr(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *str, char str2);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void my_swap(char **a, char **b);
char *my_revstr(char *str);
int error(char const *str);
void pong_(char **argv);
int error_handling(struct BSQ *file);
int count_my_lines(struct BSQ *file);
int **map_to_array_int(struct BSQ *file);
int count_lines_loop(BSQ *file, int *i, int *char_line_ref, int *char_line);
void find_my_square(BSQ *file __attribute__((unused)));
char **map_to_array_char(struct BSQ *file);
void replace_my_map(BSQ *file, int x, int y, int i);
int map_count_columns(struct BSQ *file);
void find_my_columns_square(BSQ *file);
#endif