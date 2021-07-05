/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 01:57:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/05 16:43:11 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

/* find elements in the stack B that fit in the LIS */
int		any_in_lis_range(list_of_arrays *arrays, int *store)
{
	int iter;
	int min;
	array *this_stack;
	array *other_stack;
	int start;
	int end;

	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	start = this_stack->start_of_lis_range;
	end = this_stack->end_of_lis_range;
	iter = -1;
	min = INT_MAX;
	while (++iter < other_stack->count)
		if ((other_stack->stack[iter] > start && other_stack->stack[iter] < end && !this_stack->lis_circled) ||
			(other_stack->stack[iter] > start && other_stack->stack[iter] > end && end == this_stack->lis[0] && this_stack->lis_circled) || 
			(other_stack->stack[iter] < start && other_stack->stack[iter] < end && end == this_stack->lis[0] && this_stack->lis_circled))

		{
			if (other_stack->stack[iter] < min)
			{
				min = other_stack->stack[iter];
				*store = min;
			}
		}
	if (min != INT_MAX)
		return (1);
	else
		return (0);
}

/* next signifies a trigger to consider the LIS built after
 * the current one */
int		element_is_in_lis(array *stack, int elem, int next)
{
	int	iter;

	next += 1;
	iter = -1;
	while (++iter < stack->lis_size)
		if (stack->lis[iter] == elem)
			return (1);
	return (0);
}

void	update_lis_with_elem(array *stack, int elem)
{
	int stop;
	int iter;

	iter = 0;
	while (stack->lis[iter] < elem && iter < stack->lis_size)
		iter++;
	stop = iter;
	iter = stack->lis_size + 2;
	while (--iter != stop)
		stack->lis[iter] = stack->lis[iter - 1];
	stack->lis[stop] = elem;
	stack->lis_size++;
	if (stack->lis_size == stack->count)
		stack->sorted = 1;
}

/* will keep track of the two elements in the LIS that accept
 * any number in between; this number will be swapped into the range
 * instead of being pushed to the other side
 *
 * eg: 1 6 3 10 has LIS of 1 3 10; but 6 can be swapped with 3,
 * thus increasing the sequence*/
void	update_lis_interval(array *stack, int initialize)
{
	int iter;
	int size;

	if (initialize)
	{
		iter = 0;
		while (!element_is_in_lis(stack, stack->stack[iter], 0))
			iter++;
		stack->current_range = 0;
		while (stack->lis[stack->current_range] != stack->stack[iter])
			stack->current_range++;
		stack->current_range--;
	}
	size = stack->lis_size;
	if (stack->lis_size > 1)
	{
		stack->start_of_lis_range = stack->lis[(stack->current_range + stack->lis_size)% stack->lis_size];
		stack->end_of_lis_range = stack->lis[(++stack->current_range + stack->lis_size)% stack->lis_size];
		if (stack->current_range > stack->lis_size - 1)
		{
			stack->end_of_lis_range = stack->lis[0];
			if (!initialize)
				stack->lis_circled = 1;
			stack->current_range = 0;
		}
		else if (stack->lis_circled)
			stack->lis_circled = 0;
	}
}

/* which is an index */
void	print_lis(array *stack)
{
	int iter;

	printf("longest sequence is: \n");
	iter = -1;
	while (++iter < stack->lis_size)
		printf("%d ", stack->lis[iter]);
	printf("\n%d elements long\n", stack->lis_size);
}

int		is_sorted(array *stack)
{
	int iter;

	iter = -1;
	while(++iter < stack->count - 2)
		if (stack->stack[iter] > stack->stack[iter + 1])
			return (0);
	return (1);
}
