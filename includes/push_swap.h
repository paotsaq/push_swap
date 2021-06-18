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
	char	identity;
	int		*stack;
	lis		sequences;
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
void	rotate(array *stack);
void	rotate_both(array *stack_a, array *stack_b);
void	reverse_rotate(array *stack);
void	reverse_rotate_both(array *stack_a, array *stack_b);
void	reverse_both(array *stack_a, array *stack_b);
void	swap(array *stack);
void	swap_both(array *stack_a, array *stack_b);
void	push(array *gives, array *receives);
void	do_operations(array *stack_a, array *stack_b, char *buffer);
void	algo(array *stack_a, array *stack_b);
void	visualizer(array *stack_a, array *stack_b);
int		find_median(array *array);
void 	real_simple_sort(int *array, int size);

/* algorithm */
void	new_algo(array *stack_a, array *stack_b);
void	sort_by_rotation(array *stack_a, array *stack_b);
int		is_sorted(array *stack);
void	push_garbage_to_opp_stack(array *stack, array *other_stack);

/* lis */
void	find_lis(array *stack, int candidates);
void	get_lis_candidates(array *stack);
void	update_lis_with_elem(array *stack, int elem);
void	update_lis_interval(array *stack);
void	print_lis(array *stack);
int     element_is_in_lis(array *stack, int elem, int next);

/* visualization */
void	prints_array(int *array, int size);
