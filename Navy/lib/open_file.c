/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-navy-nathan.catalan
** File description:
** open_file
*/

#include "../include/my.h"

char *find_n_boat(char *map, signals_t *signals)
{
    for (int i = 0; map[i] != '\0'; i += 1) {
        if ((map[i] >= '0' && map[i] <= '9') && map[i -1] != '\n')
            signals->n_boat += 1;
    }
}

char *open_pos(char *map, char *str, signals_t *signals)
{
    int fd = open(str, O_RDONLY);
    char *pos = malloc(sizeof(char) * 32);
    if (fd < 0)
        exit(84);
    read(fd, pos, 32);
    pos[31] = '\0';
    set_boat(map, pos);
    find_n_boat(map, signals);
    return map;
}

void open_file(char *str, int readan, signals_t *signals)
{
    int fd = open("map", O_RDONLY);
    char *map = malloc(sizeof(char) * 180);
    char *map_save;

    if (fd < 0)
        exit(84);

    read(fd, map, 180);
    map[179] = '\0';
    map_save = my_strdup(map);
    open_pos(map, str, signals);
    if (readan == 1) {
        my_printf("my positions:\n%s\n\n", map);
        my_printf("enemy's positions:\n%s\n\n", map_save);
    }
    signals->map = map;
    signals->empty_map = map_save;
}
