/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_sort_int_array.c
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int transit;

    while (i != size) {
        if (array[i] > array[i + 1]) {
            transit = array[i];
            array[i] = array[i + 1];
            array[i + 1] = transit;
            i = 0;
        } else {
            i += 1;
        }
    }
}
