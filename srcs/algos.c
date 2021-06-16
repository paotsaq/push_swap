/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/06/16 22:46:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	element_is_in_lis(array *stack, int elem)
{
	int	iter;

	iter = -1;
	while (++iter < stack->count)
		if (stack->lis_array[iter] == elem)
			return (1);
	return (0);
}


/* binary search
static int	element_is_in_lis_binary(array *stack, int elem, int first, int last)
{
	int half;

	half = (last - first) / 2;
	if (first > last)
		return (0);
	else if (stack->lis_array[half] < elem)
		return element_is_in_lis(stack, elem, half + 1, last);
	else if (stack->lis_array[half] == elem)
		return (1);
	else
		return element_is_in_lis(stack, elem, first, half - 1);
} */


/* will keep track of the two elements in the LIS that accept
 * any number in between; this number will be swapped into the range
 * instead of being pushed to the other side
 *
 * eg: 1 6 3 10 has LIS of 1 3 10; but 6 can be swapped with 3,
 * thus increasing the sequence*/
void	update_lis_interval(array *stack, int lis_elem)
{
	if (stack->lis_size > 1)
	{
		stack->start_of_lis_range = stack->lis[current_range];
		stack->end_of_lis_range = stack->lis[++current_range];
	}
}

void	push_garbage_to_opp_stack(array *stack, array *other_stack)
{
	int iter_stack;
	int elem;

	stack->current_range = 0;
	stack->end_of_lis_range = stack->lis_array[0];
	iter_stack = -1;
	while (iter_stack++ < stack->count)
	{
		elem = stack->stack[iter_stack];
		if (element_is_in_lis(stack, elem))
		{
			do_operations(stack, stack_b, "ra");
			update_lis_interval(stack, elem);
		}
		else
		{
			/* if next elem in stack is the end of range and
			 * if a swap might prolong the LIS */
			if (stack->stack[iter_stack + 1] == stack->start_of_lis_range
				&& stack->stack[iter_stack] > stack->start_of_lis_range
				&& stack->stack[iter_stack] < stack->end_of_lis_range)
				do_operations(stack, stack_b, "sa");
			else
				do_operations(stack, stack_b, "pa");
			iter_stack = -1;
		}
	}
}

/* it could be possible to shove above median garbage on top,
 * below median garbage below */
void	new_algo(array *stack_a, array *stack_b)
{
	push_garbage_to_opp_stack(stack_a, stack_b);
}
