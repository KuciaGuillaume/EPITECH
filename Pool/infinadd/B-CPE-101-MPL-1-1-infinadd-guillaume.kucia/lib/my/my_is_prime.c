/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-Cworkshoplib-guillaume.kucia
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    double i = 2;
    double prime = 0;
    int prime2 = 0;

    if (nb < 2) {
        return 0;
    }
    while (i < nb) {
        prime = (double)nb;
        prime2 = nb / i;
        if ((prime / i) > prime2) {
            i = i + 1;
        }
        else {
            return 0;
        }
    }
    return 1;
}
