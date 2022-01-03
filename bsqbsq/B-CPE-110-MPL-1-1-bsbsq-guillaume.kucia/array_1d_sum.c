/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** array_1d_sum.c
*/

int array_1d_sum(int const *arr, int size)
{
    int i = 0;
    int sum = 0;

    while (i != size) {
        sum += arr[i];
        i += 1;
    }
    return sum;
}
