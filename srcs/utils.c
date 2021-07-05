
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/07/05 07:45:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this goes away after implementing a median algorithm */
void real_simple_sort(int *array, int size)
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

int	find_median(array *array)
{
	int copy[array->count];
	int i;

	i = -1;
	while(++i < array->count)
		copy[i] = array->stack[i];
	real_simple_sort(copy, array->count);
	return copy[(int)array->count / 2];
}

int	stack_is_sorted(array *stack, int median)
{
	int iter;
	int orientation;
	int limit;

	iter = -1;
	orientation = -1;
	/* this won't fly!!! 🚨 */
	if (median)
		limit = median - 1;
	else
		limit = stack->count - 1;
	while (++iter < limit)
		if (stack->stack[iter] > stack->stack[iter + 1])
		{
			iter = stack->count;
			while (--iter > 1)
				if (stack->stack[iter] > stack->stack[iter - 1])
					return (0);
			if (iter == 1 && stack->stack[iter] < stack->stack[iter -1])
			{
				stack->orientation = 1;
				return (1);
			}
			else
				return (0);
		}
	stack->orientation = 0;
	return (1);
}
