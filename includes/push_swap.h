#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct array {
	int		*stack;
	int		*count;
	int		*size;
}				array;

typedef struct stacks {
	int		a[500];
	int		b[500];
	int		size;
	int		lis[500];
	int		lis_size;
	int		a_count;
	int		b_count;
	int		sorted;
	int		sorted_size;
	char		comm[10000][5];
	int		comm_index;
	array		array_a;
	array		array_b;
}			  s_stacks;


typedef struct list_of_arrays {
	struct array arrays[50];
	int	count;
	int sorted[500];
	int	sorted_size;
	char comm[10000][4];
	int comm_index;
}				list_of_arrays;

typedef struct chains {
	int	heads[500][500];
	int	tails[500];
	int	sizes[500];
	int	*largest_active;
	int	largest_size;
	int	count;
}				chains;

typedef struct move_info {
	int a_elem;
	int b_elem;
	int a_top;
	int b_top;
	int a_bot;
	int b_bot;
	int min;
	int same;
	char dir_a[5];
	char dir_b[5];
}			   move_info;

typedef struct best_move {
	move_info moves[500];
	int	      minimum_cost;
	int	      elem;
	int		  minimum_cost_index;
	int		  index;
}				best_moves;

int		main(int argc, char **argv);
/* stack operations */
void	rotate(array *stack);
void	rotate_both(array *stack_a, array *stack_b);
void	reverse_rotate(array *stack);
void	reverse_rotate_both(array *stack_a, array *stack_b);
void	reverse_both(array *stack_a, array *stack_b);
void	swap(array *stack);
void	swap_both(array *stack_a, array *stack_b);
void	push(array *gives, array *receives);
void	do_operations(s_stacks *stacks, char *buffer, int parity);

int pos_in_array(int *array, int elem, int limit);
/* algorithm */
void	algorithm(s_stacks *stacks);
void	sort_three(array *stack_a, array *stack_b);
void	sort_five(array *stack_a, array *stack_b);

/* array of arrays */
void	initializes_array(list_of_arrays *arrays, int size);

/* lis */
void	find_lis(s_stacks *stacks);
void	update_lis_with_elem(s_stacks *stacks, int elem);
void	print_lis(array *stack);
int		element_is_in_lis(s_stacks *stacks, int elem);
int		any_in_lis_range(list_of_arrays *arrays, int *store);
int		lis_is_found(list_of_arrays *arrays, array *stack, int limit);
int		element_lis_index(array *stack, int elem, int *lis_elem_index);
void	get_first_lis_center(array *stack);
void 	best_move_interface(s_stacks *stacks);

/* visualization */
void	prints_array(int *array, int size);
void	visualizer(array *stack_a, array *stack_b);
