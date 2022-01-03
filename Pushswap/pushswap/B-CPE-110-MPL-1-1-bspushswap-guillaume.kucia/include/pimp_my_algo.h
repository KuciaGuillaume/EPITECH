/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** my.h
*/

#ifndef	PIMP_MY_ALGO_H_
#define	PIMP_MY_ALGO_H_

#include <stdlib.h>
#include <stdio.h>

size_t get_nb_operations(void);
void rotate(void);

void swap_elem(int *array, int index1, int index2);
void sort_numbers(int *array1, int *array2, int size);
void bubble_sort_array(int *array, int size);
void rotate_left(int *array, int size);
void rotate_right(int *array, int size);
void push(int *array1, int *array2, int size);
void pop(int *array1, int *array2, int size);
int find_less_number(int *array1, int size);
void set_min_to_first_index(int *array1, int size, int pos_min);

#endif		/* !PIMP_MY_ALGO_H_ */