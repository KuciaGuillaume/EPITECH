/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-flavio.moreno
** File description:
** pushswap
*/

#ifndef TETRIS_H
    #define TETRIS_H

    #include "dirent.h"
    #include "getopt.h"
    #include "types.h"
    #include <sys/stat.h>
    #include <sys/types.h>
    #include "engine/utils/utils.h"
    #include "engine/list/list.h"
    #include "engine/location/location.h"
    #include "engine/random/random.h"
    #include "time.h"
    #include <ncurses.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define GAME get_game()
    #define CAST(type, el) ((type) el)
    #define NEW(x) malloc(sizeof(x))

struct s_game {

    Settings *settings;
    bool lose;
    WINDOW *game_window;
    WINDOW *next_piece_window;

};

struct s_settings {

    int start_level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int map_size_x;
    int map_size_y;
    bool show_next;
    bool debug;

};

struct s_tetrimino {

    int width;
    int height;
    int color;
    char *name;
    char *form;

};
struct s_tetriminos_manager {

    int tetriminos_count;
    List *tetriminos;

};

static char *board[300];

Game *get_game(void);

void load_tetriminos(void);

void load_parameters(int argc, char **argv);

void load_map_dimensions(char *dimensions);

void *malloc_val(size_t size, int i);

int my_getnbr(char const *str);

void init_settings(void);

void init_game(void);

void start_game(void);

int my_strlen(char *str);

char *my_strcpy(char *dest, char *src);

char *my_strcat(char *dest, char *src);

char *my_strdup(char *str);

int my_strcmp(char *s1 , char *s2);

#endif // TETRIS_H