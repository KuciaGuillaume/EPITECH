/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../include/tetris.h"

static void init_window(void)
{
    WINDOW *game_window = 0;
    WINDOW *next_piece_window = 0;

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    game_window = subwin(stdscr, GAME->settings->map_size_y,
        GAME->settings->map_size_x * 2,
        LINES / 2 - GAME->settings->map_size_y / 2,
        COLS / 2 - GAME->settings->map_size_x / 2);
    next_piece_window = subwin(stdscr, 5, 10, LINES / 2 - GAME->settings->map_size_y / 2, COLS / 2 + GAME->settings->map_size_x * 2);
    refresh();
    GAME->game_window = game_window;
    GAME->next_piece_window = next_piece_window;
}

static void destroy_win(void)
{
    delwin(GAME->game_window);
    delwin(GAME->next_piece_window);
    endwin();
}

int main(int argc, char **argv, char **env)
{
    /*init_game();
    init_window();
    load_parameters(argc, argv);
    start_game();
    destroy_win();*/

    load_tetriminos();
}