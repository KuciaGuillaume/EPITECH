/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** error_404.c
*/

int my_strlen(char const *str);
int infin_less(int argc, char **argv);

int infin_add_3(char **argv, int *size_Big, int spirit, int *size_Small, int arg)
{
    argv[arg][*size_Big] = spirit + 48;
    *size_Small -= 1;
    *size_Big -= 1;
}

int error_404_3(int argc, char **argv)
{
    int i = 0;
    while (argv[2][i] != '\0') {
        if ((argv[2][i] >= '0' && argv[2][i] <= '9') || (argv[1][0] == '-' || argv[2][0] == '-')){
            i += 1;
        } else {
            return 84;
        }
    }
    if (my_strlen(argv[1]) < 1 || my_strlen(argv[2]) < 1) {
        return 84;
    }
    if (argv[1][0] == '-' || argv[2][0] == '-') {
        infin_less(argc, argv);
    }
    return 0;
}

int error_404_2(int argc, char **argv)
{
    int i = 0;

    while (argv[1][i] != '\0') {
        if ((argv[1][i] >= '0' && argv[1][i] <= '9') || (argv[1][0] == '-' || argv[2][0] == '-')) {
            i += 1;
        } else {
            return 84;
        }
    }
    error_404_3(argc, argv);
}

int zero_erro(char **argv, int m, int arg, int e)
{
    int i = 0;
    m = 0;

    if (e == 1) {
        return 0;
    }
    while (argv[arg][i] != '\0') {
        if (argv[arg][i] == '0' && e == 0) {
            m += 1;
            i += 1;
        } else {
            e = 1;
            i += 1;
        }
    }
    return m;
}

int error_404(int argc, char **argv)
{
    if (argc != 3) {
        return 84;
    }
    if (argv[1][0] == '-' && argv[2][0] == '-') {
        argv[1][0] = '0';
        argv[2][0] = '0';
    }
    error_404_2(argc, argv);
}
