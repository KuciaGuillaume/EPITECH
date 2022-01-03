/*
** EPITECH PROJECT, 2021
** DAY13
** File description:
** framebuffer.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer;
    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(sizeof(width * height * 4));
    return buffer;
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[(framebuffer->width * y + x + 0)] = color.r;
    framebuffer->pixels[(framebuffer->width * y + x + 1)] = color.g;
    framebuffer->pixels[(framebuffer->width * y + x + 2)] = color.b;
    framebuffer->pixels[(framebuffer->width * y + x + 3)] = color.a;
}