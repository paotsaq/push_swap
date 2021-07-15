#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct array {
	int		*stack;
	int		*count;
	int		*size;
	int		median;
}				t_array;

typedef struct stacks {
	int			a[500];
	int			b[500];
	int			size;
	int			lis[500];
	int			lis_size;
	int			a_count;
	int			b_count;
	int			sorted;
	int			sorted_size;
	char		comm[8000][5];
	int			comm_index;
	t_array		array_a;
	t_array		array_b;
	char		opp_move[5];
}				t_stacks;

typedef struct chains {
	int	heads[500][500];
	int	tails[500];
	int	sizes[500];
	int	*largest_active;
	int	largest_size;
	int	count;
}				t_chains;

typedef struct move_info {
	int			a_elem;
	int			b_elem;
	int			a_top;
	int			b_top;
	int			a_bot;
	int			b_bot;
	int			min;
	int			same;
	char		dir_a[5];
	char		dir_b[5];
}				t_move_info;

typedef struct best_move {
	struct move_info	moves[500];
	int					minimum_cost;
	int					elem;
	int					minimum_cost_index;
	int					index;
}				t_best_moves;

void	push_swap(t_stacks *stacks);

/* parsing & validation */
int		is_duplicate(int *stack, int len, char *string);
int		parsing_of_input(char **argv, t_stacks *stacks);

/* stack operations */
void	rotate(t_array *stack);
void	reverse_rotate(t_array *stack);
void	swap(t_array *stack);
void	push(t_array *gives, t_array *receives);
void	do_operations(t_stacks *stacks, char *buffer, int parity);

/* algorithm */
void	algorithm(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	sequence_optimizer(t_stacks *stacks);

/* lis */
void	find_lis(t_stacks *stacks);
void	update_lis_with_elem(t_stacks *stacks, int elem);
int		find_index_by_size(t_chains *chain, int size);
int		get_corresponding_lis_position(t_stacks *stacks, int elem);
int		element_is_in_lis(t_stacks *stacks, int elem);

/* stack auxiliary functions */
int		remove_and_up_top(t_array *stack);
void	down_top(t_array *stack, int rotate, int *last, int *changed);
void	place_at_bottom(t_array *stack, int elem);
void	place_at_top(t_array *stack, int elem);

/* best move */
void	best_move_interface(t_stacks *stacks);

/* utils */
int		pos_in_array(int *t_array, int elem, int limit);
int		get_elem_position_in_stack(t_stacks *stacks, int elem);
int		is_sorted(t_array *stack);
void	prints_operations(t_stacks *stacks);
void	initialize_stacks(t_stacks *stacks);

#endif
