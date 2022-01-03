/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_showstr.c
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

char *my_hexa()
{
    char *hexa[] = {"00", "01" , "02", "03", "04", "05",
    "06", "07", "08", "09", "0a", "0b", "0c", "0d", "0e",
    "0e", "10", "11", "12", "13", "14", "15", "16", "17",
    "18", "19", "1a", "1b", "1c", "1d", "1e", "1f"};

    return hexa;
}

int my_showstr(char const *str)
{
    int i = 0;
    int z = 0;
    char *hexa[] = my_hexa;

    while (str[i] != '\0') {
        if (str[i] >= 0 && str[i] <= 31) {
            my_putchar('\\');
            while (z != str[i]) {
                z += 1;
            }
            my_putstr(hexa[z]);
            i += 1;
            z = 0;
        } else if (str[i] == 127) {
            my_putstr("7f");
        } else {
            my_putchar(str[i]);
            i += 1;
        }
    }
    return 0;
}

int main(void)
{
    my_showstr("j\rgdbgd\a1898");
}
