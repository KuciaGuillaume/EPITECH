/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-guillaume.kucia
** File description:
** array_id_print_chars.c
*/

void my_putchar(char c);

void array_1d_print_chars(char const *arr)
{
    int i = 0;

    while (arr[i] != '\0') {
        my_putchar(arr[i]);
        my_putchar('\n');
        i += 1;
    }
}
