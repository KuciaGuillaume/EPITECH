/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** infin_add.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib/my/my.h"

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int error_404(int argc, char **argv);
int infin_add_3(char **argv, int *size_Big, int spirit, int *size_Small, int arg);
int zero_erro(char **argv, int m, int arg, int e);

int operator_size_Big(char **argv, int *arg, int *arg2)
{
    if (my_strlen(argv[1]) > my_strlen(argv[2])) {
        *arg = 1;
        *arg2 = 2;
        return my_strlen(argv[1]);
    } else {
        *arg = 2;
        *arg2 = 1;
        return my_strlen(argv[2]);
    }
}

int operator_size_Small(char **argv)
{
    if (my_strlen(argv[1]) > my_strlen(argv[2])) {
        return my_strlen(argv[2]);
    } else {
        return my_strlen(argv[1]);
    }
}

int infin_loop(int *spirit, char **argv, int *size_Big, int arg, int *e)
{
    int RTemp = 1;

    while (RTemp == 1 && *spirit > 9) {
        *spirit -= 10;
        argv[arg][*size_Big] = *spirit + 48;
        RTemp = 1;
        *size_Big -= 1;
        if (*size_Big == (-1)) {
            my_putchar('1');
            *e = 1;
            break;
        }
        *spirit = (argv[arg][*size_Big] -48) + RTemp;
    }
}

int infin_add_2(int argc, char **argv, int spirit, int m)
{
    int arg = 0;
    int arg2 = 0;
    int size_Big = operator_size_Big(argv, &arg, &arg2) - 1;
    int size_Small = operator_size_Small(argv) - 1;
    int size_temp;
    int RTemp;
    int e = 0;

    while (size_Small != (-1)) {
        spirit = (argv[arg][size_Big] - 48) + (argv[arg2][size_Small] - 48);
        if (spirit > 9) {
            size_temp = size_Big;
            infin_loop(&spirit, argv, &size_Big, arg, &e);
            argv[arg][size_Big] = spirit + 48;
            RTemp = 0;
            size_Small -= 1;
            size_Big = size_temp - 1;
        } else {
            infin_add_3(argv, &size_Big, spirit, &size_Small, arg);
        }
    }
    m = zero_erro(argv, m, arg, e);
    if (m != 0) {
        my_putstr(&argv[arg][m]);
    } else {
        my_putstr(argv[arg]);
    }
}

int main(int argc, char **argv)
{
    int m;
    int spirit = error_404(argc, argv);

    if (spirit == 84) {
        write(2,"Invalid input", 14);
        return 84;
    }
    infin_add_2(argc, argv, spirit, m);
}
