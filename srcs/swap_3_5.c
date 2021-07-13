/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:45:44 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 12:24:03 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* determines whether to fetch top or bottom of stack
 * (rra or ra) for reducing of instructions
 * ra: shift up all elements
 * rra: shift down all elements
 * 1 is ra; 0 is rra */
static int determines_rotation(array *stack, int median)
{
	int first_above_top;	
	int i;	

	first_above_top = -1;
	i = -1;
	while (++i <= (int)(*stack->size / 2))
		if (stack->stack[i] < median)
		{
			first_above_top = i;
			break;
		}
	i = 0;
	while (i <= first_above_top)
		if (stack->stack[*stack->count - 1 - i++] < median)
			break;
	if (first_above_top == -1 || i < first_above_top)
		return (0);
	else
		return (1);
}

static void find_median(array *stack)
{
	int copy[5];
	int i;
	int tmp;

	i = -1;
	while(++i < *stack->count)
		copy[i] = stack->stack[i];
	i = -1;
	while (++i < *stack->count - 1)
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = -1;
		}
	}
	stack->median = copy[(int)*stack->count / 2];
}

static void	swap_both_interface(s_stacks *stacks)
{
	if (stacks->b[0] > stacks->b[1])
		do_operations(stacks, "s", 0);
	else
		do_operations(stacks, "ss", 0);
}

/* sorts a three-element stack
 * while looking for opportunities to swap both */
void	sort_three(s_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[1])
	{
		if (stacks->a[0] < stacks->a[2])
		{
			swap_both_interface(stacks);
			do_operations(stacks, "r", 0);
		}
		else
			do_operations(stacks, "revr", 0);
	}
	else
	{
		if (stacks->a[0] < stacks->a[2])
			swap_both_interface(stacks);
		else if (stacks->a[1] < stacks->a[2])
			do_operations(stacks, "r", 0);
		else
		{
			swap_both_interface(stacks);
			do_operations(stacks, "revr", 0);
		}
	}
}

void	sort_five(s_stacks *stacks)
{
	int numbers_to_pass;

	numbers_to_pass = 0;
	find_median(&stacks->array_a);
	if (!is_sorted(&stacks->array_a) && stacks->a_count > 0)
	{
		while (numbers_to_pass < (int)stacks->sorted_size / 2)
			if (stacks->a[0] < stacks->array_a.median)
			{
				do_operations(stacks, "p", 0);
				numbers_to_pass++;
			}
			else
			{
				if (determines_rotation(&stacks->array_a, 
					stacks->array_a.median) == 1)
					do_operations(stacks, "r", 0);
				else
					do_operations(stacks, "revr", 0);
			}
		if (!is_sorted(&stacks->array_a))
			sort_three(stacks);
		while (*stacks->array_b.count != 0)
			do_operations(stacks, "p", 1);
	}
}
