/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 05:58:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/04 08:17:50 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void merge_sequences(array *array, int start, int end)
{
	int i;

	/* how to efficiently count (and update) the number of ones,
	 * ie. the largest chain, without traversing the buffers
	 * too often? */
	// count_ones(array,
	i = start;
	while (i <= end)
		largest_seq_buf[i] = pot_seq_buff[i];

}

static	int	count_ones(array *array, int index)
{
	int count;
	int iter;

	count = 0;
	iter = -1;
	while (++iter < array->count)
		if (array->largest_seq_buf[iter] == 1)
			count++;
	return (count);
}

/* checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3) */
void	check_chain_iter(array *array)
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
					array->largest_chain_size < chain_size)
					merge_sequences(array, i, iter);
				else
				{
					array->pot_seq_buf[iter] = 1;
					chain_size++;
					current = array->stack[iter++];
				}
			}
		}
	}
}

void	check_chain_rec(array *array, int start, int pos)
{
	int i;
	int iter;
	int current;

	if (start < array->count)
		if (array->stack[pos] > start)
		{
			array->pot_seq_buf[i] = 1;
			if (array->largest_seq_buf[iter] == 1)
			check_chain_rec(pos, pos + 1);
		}
		else
			check_chain_rec(start, pos + 1);

