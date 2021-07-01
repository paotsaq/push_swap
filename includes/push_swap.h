#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct lis {
	int		*lis[500];
	int		sizes[500];
	int		rotations[500];
	int		count;
}				lis;

typedef struct array {
	int		identity;
	int		stack[500];
	int		lis[500];
	int		lis_size;
	int		rotations;
	int		lis_candidates[500];
	int		lis_candidates_size;
	int		count;
	int		size;
	int		max;
	int		min;
	int		current_range;
	int		start_of_lis_range;
	int		end_of_lis_range;
	int		sorted;
}				array;

typedef struct list_of_arrays {
	struct array arrays[50];
	int	count;
}				list_of_arrays;

typedef struct chains {
	int	heads[500][500];
	int	tails[500];
	int	sizes[500];
	int	*largest_active;
	int	largest_size;
	int	*really_largest_active;
	int	really_largest_size;
	int	count;
}				chains;

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
void	do_operations(list_of_arrays *arrays, char *buffer, int parity);
int		find_median(array *array);
void 	real_simple_sort(int *array, int size);

/* algorithm */
void	break_into_lis_algorithm(list_of_arrays *arrays);
void	sort_by_rotation(array *stack_a, array *stack_b);
int		is_sorted(array *stack);
void	push_garbage_to_opp_stack(array *stack);

/* array of arrays */
void	initializes_array(list_of_arrays *arrays, int size);

/* lis */
void	find_lis(array *stack);
void	get_lis_candidates(array *stack);
void	update_lis_with_elem(array *stack, int elem);
void	print_lis(array *stack);
int     element_is_in_lis(array *stack, int elem, int next);
void	update_lis_interval(array *stack, int initialize);

/* visualization */
void	prints_array(int *array, int size);
void	visualizer(array *stack_a, array *stack_b);
