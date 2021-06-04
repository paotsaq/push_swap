/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 05:58:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/04 13:31:54 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void merge_sequences(array *array, int *start, int *end)
{
	int i;
	int j;

	if (start)
		i = *start - 1;
	else
		i = -1;
	if (end)
		j = *end;
	else
		j = 0;

	while (++i <= j)
		array->largest_seq_buf[i] = array->pot_seq_buf[i];
	ft_bzero(array->pot_seq_buf, array->size);
}

static	int	count_ones(array *array, int *sequence, int start, int end)
{
	int count;
	int iter;

	count = 0;
	iter = start;
	while (++iter < end)
		if (sequence[iter] == 1)
			count++;
	return (count);
}

/* checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3) 
void	check_chain_iter(array *array)
{
	int i;
	int iter;
	int current;
	int chain_size;

	 fixes position of the first chain element
	i = -1;
	while (++i < array->count)
	{
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
*/

/* first call is check_chain_rec(array, 0, 0, 0) */
void	check_chain_rec(array *array, int start, int last, int pos)
{
	int i;
	int iter;

	/* if you get to the end of the array,
	 * there were no conflicting chains and thus
	 * the longest chain shall be saved */ 
	if (start >= array->count)
	{
	   	ones = count_ones(array, array->pot_seq_buf, 0, array->count - 1);
   		if (ones > array->largest_chain_size)
		{
			/* is that so? */
			merge_sequences(array, NULL, NULL);
			array->largest_chain_size = ones;
		}
	}
	else if (array->stack[pos] >= array->stack[last])
	{
		array->pot_seq_buf[i] = 1;
		if (array->largest_seq_buf[pos] == 1)
			merge_sequences(array, start, pos);
		else
			check_chain_rec(array, start, pos, pos + 1);
	}
	check_chain_rec(start, last, pos + 1);
}

void	run_checks(array *array)
{
	int i;

	i = 0;
	while (i < array->count)
	{
		check_chain_rec(array, i, i, i);
	}
}
