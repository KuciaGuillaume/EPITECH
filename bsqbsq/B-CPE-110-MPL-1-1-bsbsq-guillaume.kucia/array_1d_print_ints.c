/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** array_1d_print_ints.c
*/


void my_putchar(char c);
int my_put_nbr(int nb);

void array_1d_print_ints(int const *arr, int size)
{
    int i = 0;

    while (i != size) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
        i += 1;
    }
}
