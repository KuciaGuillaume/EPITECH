/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** my.h
*/

#ifndef GEN_H_
    #define GEN_H_

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

enum types {
    IMPERFECT,
    PERFECT,
};

typedef struct gen_s {
    int size_x;
    int size_y;
    char **maze;
    int type;
} gen_t;

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
bool nequal(char *s1, char *s2, int n);
bool enqual(char *s1, char *s2);

void *cstr(char *opt, ...);
void print_maze(gen_t *gen);
void perfect_and_imperfect(gen_t *gen, int y, bool wall);

#endif // GEN_H_ //
