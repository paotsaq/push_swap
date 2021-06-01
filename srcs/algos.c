/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:35 by apinto            #+#    #+#             */
/*   Updated: 2021/06/01 08:52:38 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this goes away after implementing a median algorithm */ 
static 	void real_simple_sort(int *array, int size)
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

static	int	find_median(array *array)
{
	int copy[array->size];
	int i;

	i = -1;
	while(++i < array->size)
		copy[i] = array->stack[i];

	real_simple_sort(copy, array->size);

	return copy[(int)array->size / 2];
}

int		is_sorted(array *stack)
{
	int i;

	i = -1;
	if (stack->count > 0)
		while (stack->stack[++i + 1])
			if (stack->stack[i] > (stack->stack[i + 1]))
				return (0);
	return (1);
}

static void	swap_both_interface(array *stack, array *other_stack)
{
	if (!is_sorted(other_stack))
		do_operations(stack, other_stack, "sa");
	else
		do_operations(stack, other_stack, "ss");
}

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
	while (++i <= (int)(stack->size / 2))
		if (stack->stack[i] < median)
		{
			first_above_top = i;
			break;
		}
	i = 0;
	while (i <= first_above_top)
		if (stack->stack[stack->count - 1 - i++] < median)
			break;
	if (first_above_top == -1 || i < first_above_top)
		return (0);
	else
		return (1);
}

/* sorts a three-element stack 
 * while looking for opportunities to swap both 
 TODO how to keep track of which stack is which? */
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

/* this workflow sorts five elems in a given stack
 * reducing it to a case of 3 - 2 */
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
