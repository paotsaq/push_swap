/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:45:44 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 08:26:49 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void real_simple_sort(int *array, int size)
{
	int i;
	int tmp;

	i = -1;
	while (++i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = -1;
		}
	}
}

static int	find_median_and_sort_array(list_of_arrays *arrays)
{
	int *copy;
	int i;
	array *this_stack;

	this_stack = &arrays->arrays[arrays->count - 2];
	copy = arrays->sorted;
	i = -1;
	while(++i < *this_stack->count)
		copy[i] = this_stack->stack[i];
	real_simple_sort(copy, *this_stack->count);
	arrays->sorted_size = i;
	return copy[(int)this_stack->count / 2];
}

static void	swap_both_interface(array *stack, array *other_stack)
{
	if (other_stack->stack[0] > other_stack->stack[1])
		do_operations(stack, other_stack, "sa");
	else
		do_operations(stack, other_stack, "ss");
}

/* sorts a three-element stack
 * while looking for opportunities to swap both */
void	sort_three(array *stack_a, array *stack_b)
{
	if (stack_a->stack_a[0] < stack_a->stack_a[1])
	{
		if (stack_a->stack_a[0] < stack_a->stack_a[2])
		{
			swap_both_interface(stack_a, stack_b);
			do_operations(stack_a, stack_b, "ra");
		}
		else
			do_operations(stack_a, stack_b, "rra");
	}
	else
	{
		if (stack_a->stack_a[0] < stack_a->stack_a[2])
			swap_both_interface(stack_a, stack_b);
		else if (stack_a->stack_a[1] < stack_a->stack_a[2])
			do_operations(stack_a, stack_b, "ra");
		else
		{
			swap_both_interface(stack_a, stack_b);
			do_operations(stack_a, stack_b, "rra");
		}
	}
}

void	sorts_five(s_stacks *stacks)
{
	int median;
	int numbers_to_pass;

	numbers_to_pass = -1;
	median = find_median(stacks->a);
	if (!is_sorted(stack_a) && stacks->a_count > 0)
	{
		while (++numbers_to_pass < (int)stacks->sorted_size / 2)
			if (stack_a->stack[0] < median)
				do_operations(stack_a, stack_b, "pa");
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
