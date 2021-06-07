/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:45:44 by apinto            #+#    #+#             */
/*   Updated: 2021/06/07 08:59:05 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* static void	swap_both_interface(array *stack, array *other_stack)
{
	if (!is_sorted(other_stack))
		do_operations(stack, other_stack, "sa");
	else
		do_operations(stack, other_stack, "ss");
}
*/
/* sorts a three-element stack
 * while looking for opportunities to swap both
 TODO how to keep track of which stack is which? 
void	sort_three(array *stack, array *other_stack)
{
	if (stack->stack[0] < stack->stack[1])
	{
		if (stack->stack[0] < stack->stack[2])
		{
			swap_both_interface(stack, other_stack);
			do_operations(stack, other_stack, "ra");
		}
		else
			do_operations(stack, other_stack, "rra");
	}
	else
	{
		if (stack->stack[0] < stack->stack[2])
			swap_both_interface(stack, other_stack);
		else if (stack->stack[1] < stack->stack[2])
			do_operations(stack, other_stack, "ra");
		else
		{
			swap_both_interface(stack, other_stack);
			do_operations(stack, other_stack, "rra");
		}
	}
}

 this workflow sorts five elems in a given stack
 * reducing it to a case of 3 - 2 
void	sorts_five(array *stack_a, array *stack_b)
{
	int median;
	int numbers_to_pass;

	numbers_to_pass = 0;
	median = find_median(stack_a);
	visualizer(stack_a, stack_b);
	printf("sorting until numbers_to_pass is < %d\n", stack_a->size / 2);
	if (!is_sorted(stack_a) && stack_a->count > 0)
	{
		while (numbers_to_pass < (int)stack_a->size / 2)
			if (stack_a->stack[0] < median)
			{
				do_operations(stack_a, stack_b, "pa");
				numbers_to_pass++;
			}
			else
			{
				if (determines_rotation(stack_a, median) == 1)
					do_operations(stack_a, stack_b, "ra");
				else
					do_operations(stack_a, stack_b, "rra");
			}
		if (!is_sorted(stack_a))
			sort_three(stack_a, stack_b);
		while (stack_b->count != 0)
			do_operations(stack_a, stack_b, "pb");
	}
}
*/
