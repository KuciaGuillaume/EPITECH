/*
** EPITECH PROJECT, 2021
** bootstrap my_runner
** File description:
** my_runner.c
*/

#include "include/my.h"

int game_loop(window_t *window, node_t *node)
{
    while (sfRenderWindow_isOpen(window->window)) {
        if (game_event(window, node) == 84) {
            return 84;
        }
        sfRenderWindow_clear(window->window, sfBlack);
        foreach(node, window, draw_object);
        foreach(node, window, box_button);
        draw_score(window);
        sfRenderWindow_display(window->window);
        set_difficulty(window);
    }
    return 0;
}

int create_window(window_t *window, node_t **node)
{
    sfVideoMode mode = {1920, 1080, 32};
    window->filepath_score = "lib/Assets/Contents/map_score.txt";
    initiate_window(window);
    if (set_objects_1(node, window->filepath_map, window) == 84)
        return 84;
    if (load_map(node, window->filepath_map, window) == 84) {
        return 84;
    }
    set_objects_2_1(node);
    window->window = sfRenderWindow_create(mode, "runner window",
    sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 300);
    return 0;
}

int errors(int ac, char **av, window_t *window)
{
    if (ac > 3 || ac == 1) {
        my_putstr("Wrong input, you can try this [./my_runner -h]\n");
        return 84;
    }
    if (my_strcmp("-h", av[1]) == 0) {
        informations();
        return 56;
    }
    if (ac == 3) {
        if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 50) {
            my_putstr("Wrong input, you can try this [./my_runner -h]\n");
            return 84;
        }
        window->difficulty = my_getnbr(av[2]);
    } else
        window->difficulty = 1;
    window->filepath_map = av[1];
    return 0;
}

int main(int ac , char **av)
{
    window_t window;
    node_t *node = NULL;
    int i = 0;

    i = errors(ac, av, &window);
    if (i == 84)
        return i;
    else if (i == 56)
        return 0;
    if (create_window(&window, &node) == 84)
        return 84;
    if (game_loop(&window, node) == 84) {
        return 0;
    }
    destroy_object(node, &window);
    return 0;
}
