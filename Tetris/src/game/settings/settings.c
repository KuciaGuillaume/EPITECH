/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/tetris.h"

static void load_options_three(int ch)
{
    switch (ch) {
        case 'q':
            GAME->settings->key_quit = my_getnbr(optarg);
            break;
        case 'p':
            GAME->settings->key_pause = my_getnbr(optarg);
            break;
        case 'm':
            load_map_dimensions(optarg);
            break;
    }
}

static void load_options_two(int ch)
{
    switch (ch) {
        case 'L':
            GAME->settings->start_level = my_getnbr(optarg);
            break;
        case 'l':
            GAME->settings->key_left = my_getnbr(optarg);
            break;
        case 'r':
            GAME->settings->key_right = my_getnbr(optarg);
            break;
        case 't':
            GAME->settings->key_turn = my_getnbr(optarg);
            break;
        case 'd':
            GAME->settings->key_drop = my_getnbr(optarg);
            break;
        default:
            load_options_three(ch);
            break;
    }
}

static void load_options(struct option options[], int argc, char **argv)
{
    int ch = 0;

    while ((ch = getopt_long(argc, argv, "hLlrtdqpmwD",options,
        NULL)) != -1) {
        switch (ch) {
            case 'h':
                exit(23);
                break;
            case 'w':
                GAME->settings->show_next = 0;
                break;
            case 'D':
                GAME->settings->debug = 1;
                break;
            default:
                load_options_two(ch);
                break;
        }
    }
}

void load_parameters(int argc, char **argv)
{
    static struct option options[] = {
        {"help", no_argument, NULL, 'h'},
        {"level",  required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {NULL, 0, NULL, 0}
    };
    load_options(options, argc, argv);
}

void init_settings(void)
{
    Settings *settings = malloc(sizeof(Settings));

    settings->start_level = 1;
    settings->map_size_y = 20;
    settings->map_size_x = 10;
    settings->show_next = 1;
    settings->debug = 0;
    settings->key_left = 65;
    settings->key_right = 68;
    settings->key_turn = 67;
    settings->key_drop = 66;
    settings->key_quit = 113;
    settings->key_pause = 32;
    GAME->settings = settings;
}
