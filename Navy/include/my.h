/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
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

#ifndef HEADERS
    #define HEADERS
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

typedef struct boat_s
{
    int x1;
    int x2;
    int y1;
    int y2;
    int size_ligne;
    int col;
    char charx1;
    char charx2;
    char name_boat;
    int size_name_boat;
}boat_t;

typedef struct signals_s
{
    int play;
    int player;
    char *map;
    char *empty_map;
    int type;
    int i;
    int signal_i;
    int signal_a;
    int n_boat;
    int enemy_alive;
    int alive;
}signals_t;

typedef struct signals_info_s
{
    int a;
    int e;
    int h;
}signals_info_t;

char name_map[400];

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
char *my_strcat_char(char *dest, char src);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
void flag_h(void);
void respect_normes(int *i, char *my_str, va_list list);
void respect_normes1(int *i, char *my_str, va_list list);
void sig_info(int sig, siginfo_t *siginfo);
int my_getnbr(char const *str);
void sig_info_2(int sig, siginfo_t *siginfo);
void open_file(char *str, int readan, signals_t *signals);
char *open_pos2(char *map);
char *open_pos1(char *map);
void set_boat(char *map, char *pos);
void interaction_1(int player, siginfo_t *info, signals_t *signals);
int get_reception(signals_t *signals, int sig, siginfo_t *siginfo);
void set_signals(char *enter, int player, siginfo_t *info);
void sig_info_interaction(int sig, siginfo_t *siginfo);
void draw_x(signals_t *signals, int i, char *boat);
void set_signals2(int player, siginfo_t *siginfo);
int get_info_attack_reception(char *coordinated, signals_t *signals);
void get_info_attack_back(signals_t *signals, int i, siginfo_t *siginfo);
void sig_info3(signals_info_t *si, siginfo_t *siginfo,
signals_t *signals, int player);
void back_get_info_attack(char *attack, siginfo_t *siginfo,
int player, signals_t *signals);
void set_s1_and_s2(signals_t *signals, int *s1, int *s2);

#endif
