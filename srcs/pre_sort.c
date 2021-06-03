
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/03 06:38:12 by apinto           ###   ########.fr       */
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
	int copy[array->size];
	int i;

	i = -1;
	while(++i < array->size)
		copy[i] = array->stack[i];
	real_simple_sort(copy, array->size);
	return copy[(int)array->size / 2];
}

/* (clumsily) checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3)
 *
 * Start at 4:
 *	4 1 is sorted (but assuming rotation); 4 1 5 is not
 *	Jump over 1. 4 5 6 (assuming rotation) 2 3 is sorted (ends at 4)
 *	Jump over 5. 4 6 is sorted - but 6 is already included in a sequence. Thus discard.
 *
 *
 *	*/
int	check_chain(array *array)
{
	int i;
	int iter;
	int max_chain;
	int current_chain;
	int max_starting;
	int starting;
	int current_number;
	int finished_chain;

	i = finished_chain = -1;
	/* fixes position to start counting */
	while (++i < array->count)
	{
		if (finished_chain == -1)
		array->pot_seq_buf[i] = 1;
		starting = current = array->stack[i];
		while (current_chain == 1 || starting != current)
		while (current < array->stack[iter++])
		{
			current_chain += 1;
			if (iter > array->count)
				iter = 0;
		}
		if (current_chain > max_chain)
		{
			max_chain = current_chain;
			max_starting = starting;
		}
	}
	printf("max chain is %d\nmax value is %d\n", max_chain, max_starting);
	return max_chain;
}
