/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:35 by apinto            #+#    #+#             */
/*   Updated: 2021/05/27 13:18:03 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static 	void real_simple_sort(int *array, int size)
{
	int i;
	int tmp;

	i = -1;	
	while (++i < size - 2)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

static	int	median(array *array)
{
	int copy[array->size];
	int i;

	i = -1;
	while(++i < array->size - 1)
		copy[i] = array->stack[i];

	real_simple_sort(copy, array->size);

	return copy[(int)array->size / 2];
}

void	algo(array *stack_a, array *stack_b)
{
	int median;
	int numbers_to_pass;

	numbers_to_pass = (int)array->size / 2;
	median = median(stack_a);
	printf("blond is a great record 👩‍🎤\n also median: %d  numbers_to_pass: %d\n", median(stack_b));	

	if (stack_b)
		printf("blond is a great record 👩‍🎤\n also median: %d  numbers_to_pass: %d\n", median(stack_b));	
}
