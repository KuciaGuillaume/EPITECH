/*
** EPITECH PROJECT, 2022
** corewar [WSL: Ubuntu]
** File description:
** set_interface
*/

#include "../../include/corewar.h"
#include <termios.h>
#include <unistd.h>
#define LEFT  68
#define RIGHT 67
#define DOWN  66
#define UP    65

static void print_vm_info(field_t *fields, int y)
{
    int color[4] = {31, 34, 35, 36};

    for (int x = 0; x < 64; x++) {
        if (fields[(y * 64) + x].owner_id != 0)
            printf("\e[1;%dm", color[fields[(y * 64) + x].owner_id - 1]);
        printf("%02X ", fields[(y * 64) + x].value);
        printf("\e[0m");
    }
}

int print_vm(field_t *fields)
{
    printf("\033[H");
    printf("\033[0J");
    for (int y = 0; y < 96; y++) {
        print_vm_info(fields, y);
        printf("\n");
    }
}

int getch(void)
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int get_arrow_key(void)
{
    int key[3] = {0};

    key[0] = getch();
    if (key[0] == 27) {
        key[1] = getch();
        key[2] = getch();
    }
    if (key[0] != 27 || key[1] != 91)
        return 0;
    switch (key[2]) {
        case LEFT:
            /* TODO: go back */
            break;
        case RIGHT:
            /* TODO: go front */
            break;
    }
    return 1;
}

int main_graphic_curse(field_t *fields)
{
    while (1) {
        print_vm(fields);
        for (; !get_arrow_key(););
    }
}
