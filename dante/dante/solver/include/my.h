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
#include <string.h>

#define put printf
#define ERROR exit (84);
#define Close exit (0);

#ifndef MY_H_
    #define MY_H_

typedef struct v2f_s {
    int width;
    int height;
    int full;
} v2f;

typedef struct i2f_s {
    int x;
    int y;
} i2f;

typedef struct dir_s {
    int up;
    int down;
    int right;
    int left;
} dir;

typedef struct open_node_s {
    int val;
    i2f pos;
} open_node_t;
typedef struct list_s {
    open_node_t node;
    struct list_s *next;
    struct list_s *previous;
} list_t;
typedef struct opt_t_s {
    v2f size;
    i2f begin;
    i2f end;
    i2f actualp;
    int ln;
    bool solved;
    int *v_maze;
    int *v_path;
    list_t *list;
} opt_t;

int int_size(int n);
bool allowed(char *unverified, char *library);
bool scan(char *filepath, char **buffer, int *full);

void error_handling(int ac);
void exit_msg(char *msg, int value);
void maze_solver(char *maze, int full);
opt_t init_opt(char *maze, opt_t opt, int full);
int cvt_to_hard(int x, int y, opt_t *opt);
void check_point(opt_t *opt, char *maze, int full);
void view_distance(i2f ap, opt_t *opt, char dir);
void check_arround(opt_t *opt, char *maze);
void debug_print(opt_t *opt, char *maze);
void move_to_min(opt_t *opt, char *maze);
void print_path(char *maze, opt_t *opt);
void new_node(opt_t *opt, int val, i2f pos);

#endif
