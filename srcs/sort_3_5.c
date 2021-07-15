/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:45:44 by apinto            #+#    #+#             */
/*   Updated: 2021/07/14 19:00:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_median(t_array *stack)
{
	int	copy[5];
	int	i;
	int	tmp;

	i = -1;
	while (++i < *stack->count)
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

/* sorts a three-element stack
 * while looking for opportunities to swap both */
void	sort_three(t_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[1])
	{
		if (stacks->a[0] < stacks->a[2])
		{
			do_operations(stacks, "s", 0);
			do_operations(stacks, "r", 0);
		}
		else
			do_operations(stacks, "revr", 0);
	}
	else
	{
		if (stacks->a[0] < stacks->a[2])
			do_operations(stacks, "s", 0);
		else if (stacks->a[1] < stacks->a[2])
			do_operations(stacks, "r", 0);
		else
		{
			do_operations(stacks, "s", 0);
			do_operations(stacks, "revr", 0);
		}
	}
}

void	sort_five(t_stacks *stacks)
{
	int	numbers_to_pass;

	numbers_to_pass = 0;
	find_median(&stacks->array_a);
	if (!is_sorted(&stacks->array_a) && stacks->a_count > 0)
	{
		while (numbers_to_pass < (int)stacks->sorted_size / 2)
		{
			if (stacks->a[0] < stacks->array_a.median)
			{
				do_operations(stacks, "p", 0);
				numbers_to_pass++;
			}
			else
				do_operations(stacks, "r", 0);
		}
		if (!is_sorted(&stacks->array_a))
			sort_three(stacks);
		if (is_sorted(&stacks->array_b))
			do_operations(stacks, "s", 1);
		while (*stacks->array_b.count != 0)
			do_operations(stacks, "p", 1);
	}
}
