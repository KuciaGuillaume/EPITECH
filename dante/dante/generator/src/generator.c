/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "gen.h"

int get_error(char **av)
{
    int i = 1;

    for (; i != 3; i++)
        if (!allowed(av[i], "0123456789")) {
            put("Error: invalid argument\n");
            return 84;
        }
    return 0;
}

void add_on_maze(gen_t *gen, int i, int y, bool print_wall)
{
    if (i + 1 == gen->size_x && y + 1 == gen->size_y) {
        gen->maze[y][i] = '*';
        return;
    }
    if (print_wall)
        gen->maze[y][i] = 'X';
    else
        gen->maze[y][i] = '*';
}

void add_path(bool *print_wall, int y, gen_t *gen)
{
    for(int i = 0; i != gen->size_x; i++)
        add_on_maze(gen, i, y, *print_wall);
    perfect_and_imperfect(gen, y, *print_wall);
    if (*print_wall)
        *print_wall = false;
    else
        *print_wall = true;
}

void maze_generate(int ac, char **av)
{
    gen_t gen = { 0 };
    bool print_wall = false;;

    gen.size_x = my_getnbr(av[1]);
    gen.size_y = my_getnbr(av[2]);
    if (ac < 4)
        gen.type = IMPERFECT;
    else if (equal("perfect", av[3]))
        gen.type = PERFECT;
    gen.maze = malloc(sizeof(char * ) * gen.size_y);
    for (int i = 0; i != gen.size_y; i++) {
        gen.maze[i] = malloc(sizeof(char) * gen.size_x);
        add_path(&print_wall, i, &gen);
    }
    print_maze(&gen);
}

int main(int ac, char **av)
{
    srand(time(NULL));

    if (ac  < 3 || ac > 4) {
        put("To many or to few arguments.\n");
        return 84;
    }
    if (get_error(av) != 0)
        return 84;
    maze_generate(ac, av);
    return 0;
}
