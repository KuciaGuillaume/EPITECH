/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, unsigned int bytes)
{
    char *cdest = (char *)dest;
    const char *csrc = (const char *)src;

    while (bytes) {
        *(cdest++) = *(csrc++);
        bytes--;
    }
    return dest;
}

void *my_realloc(void *ptr, size_t old_size, size_t size)
{
    void *re;

    if (!ptr) {
        re = malloc(size);
    } else {
        re = malloc(size);
        my_memcpy(re, ptr, old_size);
        free(ptr);
    }
    return re;
}