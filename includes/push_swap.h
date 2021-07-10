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
	int		orientation;
	int		count;
	int		size;
	int		max;
	int		min;
	int		lis_center;
	int		lis_left;
	int		lis_right;
	int		right_circled;
	int		left_circled;
	int		lis_circled;
	int		lis_shoved;
	int		lis_index;
	int		lis_circled_index;
	int		start_of_lis_range;
	int		end_of_lis_range;
	int		pending_lis;
	int		sorted;
}				array;

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
	int	*really_largest_active;
	int	really_largest_size;
	int	count;
}				chains;

typedef struct move_info {
	int index_a;
	int index_b;
	int distance_a;
	int distance_b;
	int direction_a;
	int direction_b;
}			   move_info;

typedef struct best_move {
	move_info moves[500];	
	int	      minimum_cost;
	int		  minimum_cost_index;
	int		  current_index;
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
void	do_operations(list_of_arrays *arrays, char *buffer, int parity);
int		find_median_and_sort_array(list_of_arrays *arrays);
void 	real_simple_sort(int *array, int size);

/* algorithm */
void	break_into_lis_algorithm(list_of_arrays *arrays);
void	sort_by_rotation(array *stack_a, array *stack_b);
int		stack_is_sorted(array *stack, int median);
void	push_garbage_to_opp_stack(array *stack);

/* array of arrays */
void	initializes_array(list_of_arrays *arrays, int size);

/* lis */
void	find_lis(array *stack);
void	get_lis_candidates(array *stack);
void	update_lis_with_elem(array *stack, int elem);
void	print_lis(array *stack);
int     element_is_in_lis(array *stack, int elem, int next);
void	create_lis_interval(array *stack);
void	update_lis_interval(array *stack);
int		any_in_lis_range(list_of_arrays *arrays, int *store);
int		lis_is_found(list_of_arrays *arrays, array *stack, int limit);
void	get_lis_center(array *stack, int index);
int		element_lis_index(array *stack, int elem, int *lis_elem_index);
void	get_first_lis_center(array *stack);
int 	get_corresponding_lis_position(array *stack, int elem);

/* visualization */
void	prints_array(int *array, int size);
void	visualizer(array *stack_a, array *stack_b);
