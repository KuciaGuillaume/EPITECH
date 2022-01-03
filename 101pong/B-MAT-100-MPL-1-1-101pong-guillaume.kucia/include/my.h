/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.kucia
** File description:
** my.h
*/

#include <math.h>

#ifndef HEADERS
    #define HEADERS
typedef struct pong pong;
struct pong
{
    float xx;
    float xx1;
    float xx2;
    float v;

    float x0;
    float y0;
    float z0;

    float x1;
    float y1;
    float z1;

    float Vx;
    float Vy;
    float Vz;

    float xtn;
    float ytn;
    float ztn;

    float ztn2;

    float n;
    int int_xx;
    int e;
    int a;
    int i;
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
void unpritable_char_e(char *str);
int octal(int nbr);
int binary(int str);
char *hexa_min(int nb, char *str, int i);
char *my_revstr(char *str);
char *hexa_maj(int nb, char *str, int i);
int error(char const *str);
int my_printf(char const *string, ...);
void pong_(char **argv);
float change_my_str(struct pong *vector, char *str);
float create_my_float(char *string, struct pong *vector);
void write_my_time_t(struct pong *vector);
#endif
