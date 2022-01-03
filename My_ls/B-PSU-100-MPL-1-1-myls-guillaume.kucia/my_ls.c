/*
** EPITECH PROJECT, 2021
** My_ls
** File description:
** my_ls.c
*/

#include "include/my.h"

void check_this_destination(option_t *opt, char **av, int i)
{
    int file_read;
    DIR *fd = opendir(av[i]);
    struct stat buf;
    file_read = stat(av[i], &buf);
    if (fd == NULL && file_read <= -1) {
        if (opt->n_dest_f != 0)
            my_printf("\n");
        my_printf("ls: impossible d'accéder à '%s':"
        " Aucun fichier ou dossier de ce type", av[i]);
        opt->n_dest_f += 1;
    } else {
        opt->n_dest_v += i;
        opt->dest_verif += 1;
        opt->passed += 1;
        opt->is_end += 1;
    }
}

int check_destinations(option_t *opt __attribute__((unused)), char **av)
{
    int i = 1;

    while (av[i] != NULL) {
        if (av[i][0] != '-' || (av[i][0] == '-' && (av[i][1] != 'l' &&
        av[i][1] != 'a' && av[i][1] != 'R' && av[i][1] != 'r' &&
        av[i][1] != 'd' && av[i][1] != 't')))
            check_this_destination(opt, av, i);
        i += 1;
    }
    if (opt->n_dest_v == 0)
        return 84;
    return 0;
}

char *find_other_directory(char **av)
{
    int i = 1;

    while (av[i] != NULL) {
        if (av[i][0] != '-')
            return av[i];
        i += 1;
    }
    return ".";
}

int check_flags(option_t *opt, char **av)
{
    char *filepath = ".";
    if (opt->dest == 1 && opt->passed <= 1) {
        if (check_destinations(opt, av) == 84)
            return 84;
        else if (opt->l != 1 && opt->n_dest_v != 0) {
            filepath = find_other_directory(av);
            opt->ls = 1;
        }
    } else if (opt->passed != 0)
        filepath = check_other_argument(opt, av);
    if ((opt->ls == 1 || opt->d == 1) && opt->l != 1) {
        print_ls(filepath, opt);
        opt->dest_verif -= 1;
    }
    if (opt->l == 1) {
        print_l(opt, av);
        opt->dest_verif -= 1;
    }
    if (opt->dest_verif > 0)
        check_flags(opt, av);
    return 0;
}

int main(int ac __attribute__((unused)), char **av)
{
    option_t opt;
    opt.error = 0;
    opt.dest = 0;
    opt.n_dest_v = 0;
    opt.n_dest_f = 0;
    opt.dest_verif = 0;
    opt.passed = 0;
    opt.is_end = 0;
    opt.passed_file = 0;
    get_settings(ac, av, &opt);
    if (opt.error == 1)
        return 84;
    if (check_flags(&opt, av) == 84)
        return 84;
    return 0;
}
