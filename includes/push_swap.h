#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct array {
	int		*stack;
	int		count;
	int		size;
	int		max;
	int		min;
	char	*pot_seq_buf;
	char	*largest_seq_buf;
	int		start_of_largest_chain;
	int		largest_chain_size;
}				array;

typedef struct chains {
	t_list	*heads;
	t_list	*tails;
	t_list	*sizes;
	t_list	*largest_active;
	int		count;
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
void	algo(array *stack_a, array *stack_b);
void	sort_by_rotation(array *stack_a, array *stack_b);
int		is_sorted(array *stack);



