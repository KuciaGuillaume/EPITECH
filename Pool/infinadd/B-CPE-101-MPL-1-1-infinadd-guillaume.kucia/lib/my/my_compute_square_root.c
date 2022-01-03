/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    while (nb != (i*i)) {
        if ((i * i) > nb) {
            return 0;
        }
        i += 1;
    }
    return i;
}
