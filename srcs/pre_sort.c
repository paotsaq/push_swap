
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/04 05:56:35 by apinto           ###   ########.fr       */
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

/* checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3) */
int	check_chain(array *array)
{
	int i;
	int iter;
	int current;
	int chain_size;

	/* fixes position of the first chain element */
	i = -1;
	while (++i < array->count)
	{
		/* might add different values for each chain */
		/* use prime numbers to decide for overlaps */
		array->pot_seq_buf[i] = 1;
		chain_size = 0;
		starting = current = array->stack[i];
		iter = i;
		while (++iter < array->count)
			if (current < array->stack[iter])
			{
				if (array->largest_seq_buf[iter] == 1 &&
					count_of_ones(iter) < chain_size)
					merge_sequences();
				array->pot_seq_buf[iter] = 1;
				chain_size++;
				current = array->stack[iter++];
			}
		}
	}
	return max_chain;
}
