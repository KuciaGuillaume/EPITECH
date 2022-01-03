/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
** File description:
** my.h
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
#include <fcntl.h>


#ifndef HEADERS
    #define HEADERS
typedef struct storage_s
{
    char *permits;
    char *directory;
    char *filename;
    char *result;
    struct passwd *pws;
    struct passwd *pws_gid;
    char *allocate_space;
    char *long_result;
    char *atime;
    int total;
    int i;

} __attribute__((packed)) storage_t;
typedef struct option_s
{
    char l;
    char r;
    char a;
    char t;
    char recursive;
    char d;
    char h;
    char error;
    char dest;
    int n_dest_v;
    int n_dest_f;
    int dest_verif;
    int passed;
    int is_end;
    int ls;
    int passed_file;
} __attribute__((packed)) option_t;
typedef struct printf pf;
struct printf
{
    char tags;
    unsigned int var;
    long long int n;
    int add_sp;
    int valide_sp;
    int more;
    int unused;
    int counter;
    int my_more_counter;
    int counter_test;
    char *print_none;
    long long int form;
};
typedef struct storage storage;
int my_printf(char const *str, ...);
void find_file_name(storage *file);
void find_file_type(storage *file, struct stat *buf);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void unpritable_char_e(char *str);
unsigned long long int octal(unsigned long long int nb);
int binary(int str);
char *hexa_min(long long int nb, char *str, long long int i);
char *my_revstr(char *str);
char *hexa_maj(long long int nb, char *str, long long int i);
int error(char const *str);
int my_printf(char const *string, ...);
void more_flags(int *i, char *my_str, va_list list, struct printf *format);
long long int my_put_nbr_long_long(long long int nb);
unsigned long long int my_put_nbr_unsigned(unsigned long long int nb);
short int my_put_nbr_short(short int nb);
unsigned short int my_put_nbr_short_unsigned(unsigned short int nb);
void verif_flags_x(int *i, char *my_str, va_list list, struct printf *format);
void write_format(int *i, char *my_str, va_list list, struct printf *format);
int verif_more_less(int *i, char *my_str, struct printf *format);
void more_steps(int *i, char *my_str, struct printf *format);
void verif_tags(char *my_str, int *i, struct printf *format);
void get_settings(int ac, char **av, option_t *opt);
void print_ls(char *filepath, option_t *opt);
void print_l(option_t *opt, char **av);
char *filepath(char **arg);
char check_loop_permits(char *filepath, int i);
char *parse_my_file(char *directory, int i, option_t *opt);
char *find_permissions(char *permits, struct stat *buf);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
void set_loop_l(storage_t *storage, struct stat *file, char *test, option_t *opt);
char *permissions(char *filename, char *permits);
char *my_strcat_char(char *dest, char src);
char *check_other_argument(option_t *opt, char **av);
char *cut_my_directory(char *directory);
#endif
