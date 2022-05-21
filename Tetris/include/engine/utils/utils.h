/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef UTILS_H
    #define UTILS_H
    #include <stdlib.h>

void *my_memcpy(void *dest, const void *src, unsigned int bytes);

void *my_realloc(void *ptr, size_t old_size, size_t size);

#endif //UTILS_H
