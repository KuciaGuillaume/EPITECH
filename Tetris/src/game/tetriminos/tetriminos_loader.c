/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../include/tetris.h"

static const char *TETRIMINOS_FOLDER_S = "tetriminos/";

static bool check_file_extension(char *file_name, char *extension)
{
    int i = 0;
    int j = 0;

    while (file_name[i]) {
        if (file_name[i] == '.')
            j = i;
        i++;
    }
    return my_strcmp(file_name + j, extension) == 0;
}

void load_tetrimino_properties(Tetrimino *tetrimino, char *filename,
    char *line)
{
    tetrimino->name = my_strdup(filename);
}

static void load_tetrimino_from_file(char *path)
{
    Tetrimino *tetrimino = NEW(Tetrimino);
    FILE *fp = fopen(path, "r");
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;

    if (!fp)
        return 84;
    line_size = getline(&line_buf, &line_buf_size, fp);

    while (line_size >= 0) {
        line_count++;
        line_size = getline(&line_buf, &line_buf_size, fp);
        printf("%s %d", line_buf, my_strlen(line_buf));
    }
}

void load_tetrimino(char *filename)
{
    char *path = 0;
    struct stat st;
    int res = 0;

    path = malloc(sizeof(char) * (my_strlen
        ((char *)TETRIMINOS_FOLDER_S) + my_strlen(filename) + 1));
    my_strcpy(path, my_strdup((char *)TETRIMINOS_FOLDER_S));
    my_strcat(path, my_strdup(filename));
    path[my_strlen(path)] = 0;
    res = stat(path, &st);
    if (res == -1 || !S_ISREG(st.st_mode) || st.st_size == 0 ||
        !check_file_extension(path, ".tetrimino"))
        return;
    load_tetrimino_from_file(path);
}

void load_tetriminos(void)
{
    DIR *d;
    struct dirent *dir;

    d = opendir(TETRIMINOS_FOLDER_S);
    if (!d)
        exit(84);
    dir = readdir(d);
    while (dir) {
        if (dir->d_name[0] != '.')
            load_tetrimino(dir->d_name);
        dir = readdir(d);
    }
}