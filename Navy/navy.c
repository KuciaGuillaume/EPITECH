/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-guillaume.kucia
** File description:
** pushswap.c
*/

#include "include/my.h"

int arg_3(char *av)
{
    for (int i = 0; av[i] != '\0'; i += 1)
        if (av[i] < '0' || av[i] > '9')
            return (84);
    return (0);
}

int error_navy(int ac, char **av)
{
    if (ac > 3 || ac == 1) {
        exit(84);
    }
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") != 0 &&
        my_strcmp(av[1], "&") != 0 && open(av[1], O_RDONLY) < 0)
            return 84;
    }
    if (ac == 3) {
        if (arg_3(av[1]) == 84)
            return (84);
        if (open(av[2], O_RDONLY) < 0)
            return (84);
    }
    return (0);
}

void get_info(char **av)
{
    struct sigaction action;
    pid_t id;
    id = getpid();
    if (my_strcmp(av[1], name_map) == 0) {
        my_printf("my_pid: %d\n", id);
        my_printf("waiting for enemy connection...\n\n");
        action.sa_sigaction = (void *)&sig_info;
        action.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
    } else if (my_strcmp(av[2], name_map) == 0) {
        my_printf("my_pid: %d\n", my_getnbr(av[1]));
        kill(my_getnbr(av[1]), SIGUSR1);
        action.sa_sigaction = (void *)&sig_info_2;
        action.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR2, &action, NULL);
        sigaction(SIGUSR1, &action, NULL);
    }
}

void get_name_of_map(char **av, int ac)
{
    if (ac == 2) {
        for (int i = 0; av[1][i]; i++)
            name_map[i] = av[1][i];
    }
    if (ac == 3) {
        for (int i = 0; av[2][i]; i++)
            name_map[i] = av[2][i];
    }
}

int main(int ac, char **av)
{
    get_name_of_map(av, ac);
    if (error_navy(ac, av) == 84)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        flag_h();
        return (0);
    }
    get_info(av);
    while (1) {};
    return (0);
}
