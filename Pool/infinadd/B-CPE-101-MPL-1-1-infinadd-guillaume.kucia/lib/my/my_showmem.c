/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_showmemR.c
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

void my_hexa(int h)
{
    char *hexa[] = {"00", "01" , "02", "03", "04", "05", "06", "07", "08",
    "09", "0a", "0b", "0c", "0d", "0e", "0e", "10", "11", "12", "13", "14",
    "15", "16", "17", "18", "19", "1a", "1b", "1c", "1d", "1e", "1f", "20",
    "21", "22", "23", "24", "25", "26", "27", "28", "29", "2a", "2b", "2c",
    "2d", "2e", "2f", "30", "31", "32", "33", "34", "35", "36", "37", "38",
    "39", "3a", "3b", "3c", "3d", "3e", "3f", "40", "41", "42", "43", "44",
    "45", "46", "47", "48", "49", "4a", "4b", "4c", "4d", "4e", "4f", "50",
    "51", "52", "53", "54", "55", "56", "57", "58", "59", "5a", "5b", "5c",
    "5d", "5e", "5f", "60", "61", "62", "63", "64", "65", "66", "67", "68",
    "69", "6a", "6b", "6c", "6d", "6e", "6f", "70", "71", "72", "73", "74",
    "75", "76", "77", "78", "79", "7a", "7b", "7c", "7d", "7e", "7f"};

    my_putstr(hexa[h]);
}

void my_hexa_adresse(char const *str, int size, int a)
{
    int h = 0;

    my_putstr("000000");
    my_hexa(a);
    my_putchar(':');
    my_putchar(' ');
}

void my_hexa_print_text(char const *str, int size, int i, int m)
{
    int t = 1;
    int s = 0;

    while (s < 16) {
        if (t == 1) {
            my_putchar(' ');
            t = 0;
        } else {
            t = 1;
        }
        if (i < m) {
            my_hexa(str[i]);
            s += 1;
            i += 1;
        } else {
            while (s < m) {
                my_putchar(' ');
                s += 1;
            }
        }
        if (m <= 16 && i >= m) {
            my_putchar(' ');
            s += 1;
        }
    }
    my_putchar(' ');
}

int my_showmem(char const *str, int size)
{
    int i = 0;
    int h = 0;
    int a = 0;
    int t = 0;
    int m = 0;

    while (str[m] != '\0') {
        m += 1;
    }

    while (i <= size) {
        my_hexa_adresse(str, size, a);
        my_hexa_print_text(str, size, i, m);
        while (t != m) {
            if (h < 16) {
                my_putchar(str[t]);
                h += 1;
                t += 1;
            } else {
                break;
            }
        }
        my_putchar('\n');
        h = 0;
        a += 16;
        i += 16;
    }
}
