/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/06/18 02:44:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	push_garbage_to_opp_stack(array *stack, array *other_stack)
{
	int iter_stack;
	int elem;
	int pause;

	find_lis(stack);
	print_lis(stack);
	get_lis_candidates(stack);
	stack->current_range = 0;
	update_lis_interval(stack);
	iter_stack = -1;
	pause = 0;
	while (!stack->sorted && iter_stack++ < stack->count)
	{
		elem = stack->stack[0];
		if (element_is_in_lis(stack, elem))
		{
			do_operations(stack, other_stack, "r");
			update_lis_interval(stack);
		}
		else
		{
			/* 1st optimization: LIS can be extended with a swap */
			if (stack->stack[1] == stack->start_of_lis_range
				&& stack->stack[0] > stack->start_of_lis_range
				&& stack->stack[0] < stack->end_of_lis_range)
			{
				do_operations(stack, other_stack, "s");
				update_lis_with_elem(stack, elem);
			}
			else
				do_operations(stack, other_stack, "p");
			iter_stack = -1;
		}
	}
	if (stack->sorted)
		while(stack->sequences.lis[stack->sequences.count][0] != stack->stack[0])
			do_operations(stack, other_stack, "r");
	else
		push_garbage_to_opp_stack(other_stack, stack);
}

/* it could be possible to shove above median garbage on top,
 * below median garbage below */
void	new_algo(array *stack_a, array *stack_b)
{
	push_garbage_to_opp_stack(stack_a, stack_b);
}
