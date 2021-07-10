
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/07/10 19:22:22 by apinto           ###   ########.fr       */
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

/* I think this can be deleted soon 🚨"
int	stack_is_sorted(array *stack, int median)
{
	int iter;
	int orientation;
	int limit;

	iter = -1;
	orientation = -1;
	/* this won't fly!!! 🚨 */
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

/* function to determine whether the stack has been sorted until a given limit */
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
}

static void	initialize_best_moves(best_moves *list)
{
	list->minimum_cost = 0;
	list->minimum_cost_index = 0;
	list->current_index = 0;
}

int	gets_distances(array *stack_a, array *stack_b)
{
	best_moves list;
	int elem_position;
	int lis_position;

	stack_a = &arrays->arrays[arrays->count - 2];
	stack_b = &arrays->arrays[arrays->count - 1];
	elem_position = -1;
	initialize_best_moves(&list);
	while (++elem_position < stack_b->count)
	{
		lis_position = get_corresponding_lis_position(stack_a, stack->b[elem_position]);
		if ((elem_position < (stack_b->count - elem_position) && lis_position < (stack_a->lis_size - lis_position)) || 	
			elem_position > (stack_b->count - elem_position) && lis_position > (stack_a->lis_size - lis_position))
		{
			list->moves[list->current_index]->distance_a;
			list->moves[list->current_index]->distance_b;
			list->moves[list->current_index]->direction_a;
			list->moves[list->current_index]->direction_b;
							


	}
}

void	fill_distances(
