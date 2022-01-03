/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** array_2d_sum.c
*/

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int x = 0;
    int y = 0;
    int sum = 0;

    while (y < nb_rows) {
        while (x < nb_cols) {
            sum += arr[y][x];
            x += 1;
        }
        y += 1;
        x = 0;
    }
    return sum;
}
