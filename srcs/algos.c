/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/01 18:10:03 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	operate_the_stack_strategically(list_of_arrays *arrays, int elem, int median)
{
	array *stack;
	array *other_stack;

	stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	/* LIS can be extended with a swap, in place.
	 * Needs further implementation (there are more conditions that
	 * benefit from swapping) */
	if ((stack->stack[1] == stack->start_of_lis_range
		&& stack->stack[0] > stack->start_of_lis_range
		&& stack->stack[0] < stack->end_of_lis_range) ||
		(stack->size >= 2 && stack->stack[1] == stack->lis[stack->lis_size - 1]
		&& stack->stack[0] > stack->stack[1]))
	{
		do_operations(arrays, "s", 0);
		update_lis_with_elem(stack, elem);
	}
	else if (elem < median)
		do_operations(arrays, "r", 0);
	else
		do_operations(arrays, "p", 0);
}

void		break_into_lis_algorithm(list_of_arrays *arrays)
{
	int elem;
	int median;
	int head_of_stack;
	array *this_stack;
	array *other_stack;

	initializes_array(arrays, 500);
	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	find_lis(this_stack);
	median = find_median(this_stack);	
	print_lis(this_stack);
	head_of_stack = this_stack->stack[0];
	while (!is_sorted(this_stack) && (head_of_stack != this_stack->stack[0] || other_stack->count == 0))
	{
		elem = this_stack->stack[0];
		if (element_is_in_lis(this_stack, elem, 0))
		{
			do_operations(arrays, "r", 0);
			update_lis_interval(this_stack, 0);
		}
		else
			operate_the_stack_strategically(arrays, elem, median);
	}
	printf("median is %d\n", median);
	printf("new lis w/ size %d\n", this_stack->lis_size);
	print_lis(this_stack);
}
