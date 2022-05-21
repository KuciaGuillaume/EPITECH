/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** cstr.h
*/

#ifndef CSTR_H_
    #define CSTR_H_

    #include "gen.h"

enum type {
    STR,
    ARRAY,
    INT,
};

typedef struct cstr_s {
    char *c_str;
    char **c_array;
    int c_n;
    int c_num;
    char type;
    bool recurency;
    char *opt;
} cstr_t;

char *move_to_next(char *str, char pipe);
int cstr_arglen(char *str, char sep);
void cstr_parsing(cstr_t *cstr, va_list list);
char *cstr_useless(char *str, char remove);
char *cstr_grab(char *str, char sep);
char *cstr_getarg(char *str, int n, char sep);
char **cstr_cattab(char **dest, char **tab);
char **cstr_cattab_str(char **dest, char *str);
void cs_cattab(cstr_t *cstr, va_list list);
bool cstr_gx(cstr_t *cstr, va_list list);
void cstr_mv(cstr_t *cstr, va_list list);
void cstr_delete(cstr_t *cstr, va_list list);
void cstr_recurrency(cstr_t *cstr, va_list list);

#endif // CSTR_H_ //
