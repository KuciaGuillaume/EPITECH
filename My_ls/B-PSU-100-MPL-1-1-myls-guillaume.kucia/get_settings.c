/*
** EPITECH PROJECT, 2021
** Code_Ls_Args
** File description:
** opt
*/

#include "include/my.h"

int find_all_arg_more(char arg, option_t *opt)
{
    if (arg == 'R') {
        opt->recursive = 1;
        return 0;
    }
    if (arg == 'd') {
        opt->d = 1;
        return 0;
    }
    if (arg == 'h') {
        opt->h = 1;
        return 0;
    }
    return 84;
}

int find_all_arg(char arg, option_t *opt)
{
    if (arg == 'l') {
        opt->l = 1;
        return 0;
    }
    if (arg == 'r') {
        opt->r = 1;
        return 0;
    }
    if (arg == 'a') {
        opt->a = 1;
        return 0;
    }
    if (arg == 't') {
        opt->t = 1;
        return 0;
    }
    return find_all_arg_more(arg, opt);
}

void find_args(char *arg, option_t *opt)
{
    int i = 0;

    while (arg[i] != '\0' && opt->error != 1) {
        if (find_all_arg(arg[i], opt) == 0) {
            i += 1;
        } else {
            opt->error = 1;
        }
    }
}

void verif_arguments(char *arg, option_t *opt)
{
    if (arg[0] == '-') {
        if (arg[1] == '\0')
            opt->dest = 1;
        arg += 1;
        find_args(arg, opt);
    } else
        opt->dest = 1;
}

void get_settings(int ac, char **av, option_t *opt)
{
    int i = 1;
    opt->ls = 0;

    if (ac > 1) {
        while (av[i] != NULL && opt->error != 84) {
            verif_arguments(av[i], opt);
            i += 1;
        }
    } else
        opt->ls = 1;
}