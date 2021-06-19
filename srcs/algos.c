/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/06/19 18:37:40 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	get_lis_candidates(stack);
	prints_array(stack->lis_candidates, stack->lis_candidates_size);
	find_lis(stack, 1);
	print_lis(stack, 1);
*/

void	push_garbage_to_opp_stack(array *stack, array *other_stack)
{
	int iter_stack;
	int elem;

	find_lis(stack, 0);
	print_lis(stack, 0);
	stack->current_range = -1;
	update_lis_interval(stack, 1);
	iter_stack = -1;
	while (!stack->sorted && stack->count != stack->sequences.sizes[stack->sequences.count -1])
	{
		elem = stack->stack[0];
		if (element_is_in_lis(stack, elem, 0))
		{
			do_operations(stack, other_stack, "r");
			update_lis_interval(stack, 0);
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
			{
				do_operations(stack, other_stack, "p");
				if (element_is_in_lis(stack, elem, 0))
				{
					/* very dangerous operation! please protect this
					 * accordingly, future alex */
					if (element_is_in_lis(stack, stack->stack[0], 0))
						do_operations(other_stack, stack, "rr");
					else if (other_stack->count > 1)
						do_operations(other_stack, stack, "r");
				}
			}
		}
		iter_stack = -1;
	}
	if (stack->count == stack->sequences.sizes[stack->sequences.count - 1])
	{
		while(stack->sequences.lis[stack->sequences.count - 1][0] != stack->stack[0])
			do_operations(stack, other_stack, "r");
		printf("ENDGAME 🍄");
	}
	else
		push_garbage_to_opp_stack(other_stack, stack);
}

void	new_algo(array *stack_a, array *stack_b)
{
	push_garbage_to_opp_stack(stack_a, stack_b);
}
