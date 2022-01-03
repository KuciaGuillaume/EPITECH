/*
** EPITECH PROJECT, 2021
** B-MAT-100-MPL-1-1-101pong-guillaume.kucia
** File description:
** write_my_time_t.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_my_angle(struct pong *vector)
{
    float rx = (vector->Vx) * (vector->Vx);
    float ry = (vector->Vy) * (vector->Vy);
    float rz = (vector->Vz) * (vector->Vz);
    float rad;
    if (vector->Vz < 0)
        rad = asinf((vector->Vz * (-1)) / sqrtf(rx + ry + rz));
    else
        rad = asinf((vector->Vz) / sqrtf(rx + ry + rz));
    float degrees = rad * 180/M_PI;
    printf("%.2f degrees\n", degrees);
}

void write_my_time_t(struct pong *vector)
{
    vector->xtn = (vector->x0+((vector->n + 1) * (vector->x1 - vector->x0)));
    vector->ytn = (vector->y0+((vector->n + 1) * (vector->y1 - vector->y0)));
    vector->ztn = (vector->z0+((vector->n + 1) * (vector->z1 - vector->z0)));
    printf("At time t + %.f, ball coordinates will be:\n", vector->n);
    printf("(%.2f, %.2f, %.2f)\n", vector->xtn, vector->ytn, vector->ztn);

    if ((vector->z1 >= 0 && vector->ztn <= 0) || (vector->z1 <= 0 && vector->ztn >= 0)) {
        printf("The incidence angle is:\n");
        write_my_angle(vector);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
}