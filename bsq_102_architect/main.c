/*
** EPITECH PROJECT, 2021
** bsq_102_architect
** File description:
** main.c
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;
    float matrice_r = 0.00;
    float result_ligne = 0.00;
    float result_direct = 0.00;
    float matrice_ligne[3][3] =
    {
        {1.00, 2.00, 3.00},
        {4.00, 5.00, 6.00},
        {7.00, 8.00, 9.00},
    };
    float matrice_colonne[3][3] =
    {
        {10.00, 11.00, 12.00},
        {13.00, 14.00, 15.00},
        {16.00, 17.00, 18.00},
    };
    while (y != 3) {
        if (x != 3) {
            matrice_r += matrice_ligne[y][x] * matrice_colonne[y][x];
            result_ligne += matrice_r;
            printf("{%2.f} ", matrice_r);
            x += 1;
        } else {
            x = 0;
            y += 1;
            printf(" | {%.2f}\n", result_ligne);
            result_direct += result_ligne;
            matrice_r = 0.00;
            result_ligne = 0.00;
        }
    }
    printf("Result total = %2.f\n", result_direct);
}