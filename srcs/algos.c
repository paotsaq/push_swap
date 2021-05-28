/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:35 by apinto            #+#    #+#             */
/*   Updated: 2021/05/28 11:47:36 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	printf("array-size: %d\n", array->size / 2);
	return copy[(int)array->size / 2];
}

int		is_sorted(array *stack)
{
	if (stack->count > 0)
		while (*(stack + 1)
			if (*stack > *(stack + 1))
				return (0);
	return (1);
}

void	sort_three(array *stack)
{
	if (stack[0] < stack[1])
	{
		if (stack[0] < stack[2]

}

void	algo(array *stack_a, array *stack_b, int choice)
{
	int median;
	int count;
	int numbers_to_pass;

	if (choice == 1)
		do_operations(stack_a, stack_b, "manual");
	numbers_to_pass = 0;
	count = 0;
	median = find_median(stack_a);
	printf("median: %d\n", median);
	//TODO make it run while stack_a is unsorted
	while (numbers_to_pass < (int)stack_a->size / 2 && count++ < 10)
	{
		if (stack_head(stack_a) > median)
		{
			do_operations(stack_a, stack_b, "pa");
			numbers_to_pass++;
		}
		else
			do_operations(stack_a, stack_b, "rr");
		visualizer(stack_a, stack_b);
	}
}
