/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 01:57:59 by apinto            #+#    #+#             */
/*   Updated: 2021/06/20 16:38:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* binary search
static int	element_is_in_lis_binary(array *stack, int elem, int first, int last)
{
	int half;

	half = (last - first) / 2;
	if (first > last)
		return (0);
	else if (stack->lis_array[half] < elem)
		return element_is_in_lis(stack, elem, half + 1, last);
	else if (stack->lis_array[half] == elem)
		return (1);
	else
		return element_is_in_lis(stack, elem, first, half - 1);
} */

/* next signifies a trigger to consider the LIS built after
 * the current one */
int		element_is_in_lis(array *stack, int elem, int next)
{
	int	iter;

	next += 1;
	iter = -1;
	while (++iter < stack->lis_size)
		if (stack->lis[iter] == elem)
			return (1);
	return (0);
}

void	update_lis_with_elem(array *stack, int elem)
{
	int stop;
	int iter;

	stop = stack->current_range;
	iter = stack->lis_size + 2;
	while (--iter != stop)
		stack->lis[iter] = stack->lis[iter - 1];
	stack->lis[stop] = elem;
	stack->lis_size++;
	if (stack->lis_size == stack->count)
		stack->sorted = 1;
}

/* will keep track of the two elements in the LIS that accept
 * any number in between; this number will be swapped into the range
 * instead of being pushed to the other side
 *
 * eg: 1 6 3 10 has LIS of 1 3 10; but 6 can be swapped with 3,
 * thus increasing the sequence*/
void	update_lis_interval(array *stack, int initialize)
{
	int iter;
	int size;

	if (initialize)
	{
		iter = 0;
		while (!element_is_in_lis(stack, stack->stack[iter], 0))
			iter++;
		stack->current_range = 0;
		while (stack->lis[stack->current_range] != stack->stack[iter])
			stack->current_range++;
	}
	size = stack->lis_size;
	if (stack->lis_size > 1)
	{
		stack->start_of_lis_range = stack->lis[stack->current_range];
		stack->end_of_lis_range = stack->lis[++stack->current_range];
	}
}

/* which is an index */
void	print_lis(array *stack)
{
	int iter;

	printf("longest sequence is: \n");
	iter = -1;
	while (++iter < stack->lis_size)
		printf("%d ", stack->lis[iter]);
	printf("\n%d elements long\n", stack->lis_size);
}
