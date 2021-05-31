/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:35 by apinto            #+#    #+#             */
/*   Updated: 2021/05/31 11:28:53 by apinto           ###   ########.fr       */
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

static	int stack_head(array *stack)
{
	if (stack->count > 0)
		return (stack->stack[0]);
	return (0);
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
 * 1 is ra; 0 is rra */
static int determines_rotation(array *stack, int median)
{
	int first_above_top;	
	int i;	

	first_above_top = 0;
	i = -1;
	while (i <= (int)(stack->size / 2))
		if (stack->stack[i] < median)
		{
			first_above_top = i;
			break;
		}
	i = 0;
	while (i <= (int)(stack->size / 2) && i < first_above_top)
		if (stack->stack[stack->size - 1 - i++] < median)
			break;
	if (i >= first_above_top);
		return
		}

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
			do_operations(stack, other_stack, "rra");
		else
		{
			swap_both_interface(stack, other_stack);
			do_operations(stack, other_stack, "ra");
		}
	}
}

void	algo(array *stack_a, array *stack_b)
{
	int median;
	int count;
	int numbers_to_pass;

	numbers_to_pass = 0;
	count = 0;
	median = find_median(stack_a);
	printf("median: %d\n", median);
	visualizer(stack_a, stack_b);
	//TODO make it run while stack_a is unsorted
	/* pushes smaller than median numbers to the other stack */
	while (numbers_to_pass < (int)stack_a->size / 2 && count++ < 10)
		if (stack_head(stack_a) < median)
		{
			do_operations(stack_a, stack_b, "pa");
			numbers_to_pass++;
		}
	/* needs to figure out which direction to go */ 
		else
			do_operations(stack_a, stack_b, "rr");
	sort_three(stack_a, stack_b);
	while (stack_b->count != 0)
		do_operations(stack_a, stack_b, "pb");
}
