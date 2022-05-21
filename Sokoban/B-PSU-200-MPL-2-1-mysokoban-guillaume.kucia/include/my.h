/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** my.h
*/

#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <curses.h>

#ifndef MY_H_
    #define MY_H_

struct sokoban_s {
    char *map;
    char *original_map;
    int objectives;
};
typedef struct sokoban_s sokoban_t;

int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
char *my_strcat_char(char *dest, char src);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
char *my_revstr(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char const *src);
char *my_itoa(int n, int space);
int int_size(int n);
void put(char const *string, ...);
char *my_calloc(char *str, int n);
char **alloc_2d_array(char *str);
int my_arraylen(char **array);
bool equal(char *s1, char *s2);
bool allowed(char *unverified, char *library);
bool scan(char *filepath, char **buffer);

int open_map(int ac, char **av, sokoban_t *sokoban);
int my_sokoban(sokoban_t * sokoban);
void move_this_x(sokoban_t *sokoban, char e, int x);
void move_this_y(sokoban_t *sokoban, char e, int x);
bool move_possible(char *map);
int calc_line(char *str);
int calc_col(char *str);
void before_closed(sokoban_t *sokoban);
void display_sokoban(sokoban_t *sokoban);

#endif
