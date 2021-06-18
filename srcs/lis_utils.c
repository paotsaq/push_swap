/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 01:57:59 by apinto            #+#    #+#             */
/*   Updated: 2021/06/18 02:51:12 by apinto           ###   ########.fr       */
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

int		element_is_in_lis(array *stack, int elem)
{
	int	iter;
	int lis_index;

	lis_index = stack->sequences.count;
	iter = -1;
	while (++iter < stack->count)
		if (stack->sequences.lis[lis_index][iter] == elem)
			return (1);
	return (0);
}

void	update_lis_with_elem(array *stack, int elem)
{
	int stop;
	int iter;
	int lis_index;

	lis_index = stack->sequences.count;
	stop = stack->current_range;
	iter = stack->sequences.sizes[lis_index] + 1;
	while (--iter != stop)
		stack->sequences.lis[lis_index][iter] = stack->sequences.lis[lis_index][iter - 1];
	stack->sequences.lis[lis_index][stop] = elem;
	stack->sequences.sizes[lis_index]++;
	if (stack->sequences.sizes[lis_index] == stack->count)
		stack->sorted = 1;
}

/* will keep track of the two elements in the LIS that accept
 * any number in between; this number will be swapped into the range
 * instead of being pushed to the other side
 *
 * eg: 1 6 3 10 has LIS of 1 3 10; but 6 can be swapped with 3,
 * thus increasing the sequence*/
void	update_lis_interval(array *stack)
{
	int lis_index;

	lis_index = stack->sequences.count;
	if (stack->sequences.sizes[lis_index] > 1)
	{
		stack->start_of_lis_range = stack->sequences.lis[lis_index][stack->current_range];
		stack->end_of_lis_range = stack->sequences.lis[lis_index][++stack->current_range];
	}
}

void	print_lis(array *stack)
{
	int iter;

	printf("longest sequence is: \n");
	iter = -1;
	while (++iter < stack->sequences.sizes[stack->sequences.count])
		printf("%d ", stack->sequences.lis[stack->sequences.count][iter]);
	printf("\n%d elements long\n", stack->sequences.sizes[stack->sequences.count]);
}

