#ifndef		PIMP_MY_ALGO_H_
# define	PIMP_MY_ALGO_H_

# include	<stdlib.h>

/* Returns the number of operations made so far. */
size_t get_nb_operations(void);

/* Pops first value of la and push it in first pos within lb */
void push(void);

/* Pops first value of lb and push it in first pos within la */
void pop(void);

/* Rotates list a (first elem becomes last) */
void rotate(void);

/* Student's function */
int		sort_numbers(int *, int *, size_t);

/* all functions */
void swap_elem(int *array, int index1, int index2);
void bubble_sort_array(int *array, int size);
void rotate_left(int *array, int size);
void rotate_right(int *array, int size);

#endif		/* !PIMP_MY_ALGO_H_ */
