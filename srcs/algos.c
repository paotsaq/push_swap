/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/06/16 08:50:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	element_is_in_lis(array *stack, int elem, int first, int last)
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
}


/* it could be possible to shove above median garbage on top,
 * below median garbage below */
void	new_algo(array *stack_a, array *stack_b)
{
	int iter_stack;
	int iter_lis;

	iter_stack = -1;
	iter_lis = -1;
	while (stack_a->count != stack_a->lis_size && iter_lis < stack_a->lis_size)
		if (element_is_in_lis(stack_a, stack_a->stack[++iter_stack], 0, stack_a->lis_size - 1))
		{
			do_operations(stack_a, stack_b, "ra");
			iter_lis++;
		}
		else
			do_operations(stack_a, stack_b, "pa");
}
