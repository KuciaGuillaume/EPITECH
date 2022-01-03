/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec.c
** File description:
** DAY05 Task02
*/

int my_compute_factorial_rec(int nb) {
    if (nb == 0) {
        return 1;
    }
    if (nb < 2147483647 && nb > -2147483647) {
    return(nb) = nb * my_compute_factorial_rec(nb - 1);
    } else {
        return 0;
    }
}

