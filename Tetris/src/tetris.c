/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../include/tetris.h"

Game *get_game(void)
{
    static Game game = {0};

    return &game;
}

void init_game(void)
{
    GAME->lose = false;
    GAME->next_piece_window = 0;
    GAME->game_window = 0;
    init_settings();
}

void start_game(void)
{
    int ch = 0;
    int row = 0;
    int col = 0;

    while (ch != GAME->settings->key_quit && !GAME->lose) {
        ch = getch();
        getmaxyx(stdscr, row, col);
        werase(GAME->game_window);
        box(GAME->game_window, ACS_VLINE, ACS_HLINE);
        box(GAME->next_piece_window, ACS_VLINE, ACS_HLINE);
        mvwprintw(GAME->game_window, 1, 1, "%d %c", row, ch);
        wrefresh(GAME->game_window);
        wrefresh(GAME->next_piece_window);
        refresh();
    }
}