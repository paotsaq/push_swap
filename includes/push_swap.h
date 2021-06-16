#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct array {
	char	identity;
	int		*stack;
	int		count;
	int		size;
	int		max;
	int		min;
	int		lis_size;
	int		lis_rotations;
	int		*lis_array;
	int		start_of_lis_range;
	int		end_of_lis_range;
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

/* chains */
int		run_checks(array *array);
void 	chain_manager(array *stack);

/* algorithm */
void	new_algo(array *stack_a, array *stack_b);
void	sort_by_rotation(array *stack_a, array *stack_b);
int		is_sorted(array *stack);
