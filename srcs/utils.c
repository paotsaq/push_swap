
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/07/11 07:17:14 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this goes away after implementing a median algorithm */
void real_simple_sort(int *array, int size)
{
	int i;
	int tmp;

	i = -1;
	while (++i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = -1;
		}
	}
}

int	find_median_and_sort_array(list_of_arrays *arrays)
{
	int *copy;
	int i;
	array *this_stack;

	this_stack = &arrays->arrays[arrays->count - 2];
	copy = arrays->sorted;
	i = -1;
	while(++i < this_stack->count)
		copy[i] = this_stack->stack[i];
	real_simple_sort(copy, this_stack->count);
	arrays->sorted_size = i;
	return copy[(int)this_stack->count / 2];
}

/* I think this can be deleted soon 🚨
int	stack_is_sorted(array *stack, int median)
{
	int iter;
	int orientation;
	int limit;

	iter = -1;
	orientation = -1;
	if (median)
		limit = median - 1;
	else
		limit = stack->count - 1;
	while (++iter < limit)
		if (stack->stack[iter] > stack->stack[iter + 1])
		{
			iter = stack->count;
			while (--iter > 1)
				if (stack->stack[iter] > stack->stack[iter - 1])
					return (0);
			if (iter == 1 && stack->stack[iter] < stack->stack[iter -1])
			{
				stack->orientation = 1;
				return (1);
			}
			else
				return (0);
		}
	stack->orientation = 0;
	return (1);
}

function to determine whether the stack has been sorted until a given limit
int	lis_is_found(list_of_arrays *arrays, array *stack, int limit)
{
	int iter;
	int lis_iter;

	lis_iter = stack->lis_size;
	iter = arrays->sorted_size;
	while(stack->lis[--lis_iter] >= limit)
		if (stack->lis[lis_iter] != arrays->sorted[--iter])
			return (0);
	return (1);
}*/

static void	initialize_best_moves(best_moves *list)
{
	list->minimum_cost = 0;
	list->minimum_cost_index = 0;
	list->current_index = 0;
}

int		gets_distances(array *stack_a, array *stack_b)
{
	best_moves list;
	int e_pos;
	int l_pos;

	e_pos = -1;
	initialize_best_moves(&list);
	while (++e_pos < stack_b->count)
	{
		l_pos = get_corresponding_lis_position(stack_a, stack->b[e_pos]);
		list->moves[list->index]->a_elem = stack_a->stack[l_pos];
		list->moves[list->index]->b_elem = stack_b->stack[e_pos];
		list->moves[list->index]->b_top = e_pos;
		list->moves[list->index]->a_top = l_pos;
		list->moves[list->index]->b_bot = (stack_b->count - e_pos);
		list->moves[list->index]->a_bot = (stack_b->count - l_pos);
		fill_distances(&list, stack_a, stack_b);
		if (list->moves[list->index]->min < list->minimum->cost)
		{
			list->minimum_cost = list->moves[list->index]->min;
			list->minimum_cost_index = e_pos;
		}
	}
	makes_distances_move(&list, stack_a, stack_b);
}

void	fill_distances(best_moves *list, array *stack_a, array *stack_b)
{
	move_info *move;

	move = best_moves->moves[list->index];
	move->same = 0;
	if (move->a_top < move->a_bot)
		ft_strlcpy(move->dir_a, "r", 5);
	else
		ft_strlcpy(move->dir_a, "revr", 5);
	if (move->b_top < move->b_bot)
		ft_strlcpy(move->dir_b, "r", 5);
	else
		ft_strlcpy(move->dir_b, "revr", 5);
	if (ft_strncmp(move->dir_a, move->dir_b, 5) == 0)
	{
		if (ft_strncmp(move->dir_a, "r", 5) == 0)
			move->min = ft_max(move->a_top, move->b_top, 2);
		else
			move->min = ft_max(move->a_bot, move->b_bot, 2);
		move->same = 1;
	}
	else if (ft_strncmp(move->dir_a, "r", 5) == 0)
		move->min = move->a_top + move->b_bot;
	else
		move->min = move->a_bot + move->b_top;
}

void	make_distances_move(best_moves *list, array *stack_a, array *stack_b)
{
	move_info *move;
	int iter;
	int min_cost;
	char *dir;

	move = list[list->minimum_cost_index];
	min_cost = list->minimum_cost;
	iter = -1;
	if (move->same)
	{
		if (ft_strncmp(move->dir_a, "r", 5) == 0)
			while (++iter < move->a_top



}
