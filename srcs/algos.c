/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/06/16 07:05:48 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		element_is_in_lis(array *stack, int elem, int top, int bottom)
{
	int half;
	top = 0;
	bottom = stack->lis_size - 1;

	half = (bottom - top) / 2;
	if (top == bottom)
	{
		if (stack->lis_array[top] == elem)
			return 1;
		else
			return 0;
	}
	else if (stack->lis_array[half] > elem)
		return element_is_in_lis(stack, elem, top, half);
	else
		return element_is_in_lis(stack, elem, half, bottom);
}


/* it could be possible to shove above median garbage on top,
 * below median garbage below */
void	new_algo(array *stack_a, array *stack_b)
{
	int iter_stack;
	int iter_lis;

	iter_stack = -1;
	iter_lis = -1;
	/* this might be unnecessary specially in small stacks */
	while (stack_a->lis_rotations && stack_a->lis_rotations-- != 0)
		do_operations(stack_a, stack_b, "ra");
	while (iter_lis < stack_a->lis_size)
		if (element_is_in_lis(stack_a, stack_a->stack[++iter_stack], 0, stack_a->lis_size - 1))
			do_operations(stack_a, stack_b, "pa");
		else
		{
			do_operations(stack_a, stack_b, "ra");
			iter_lis++;
		}
}
