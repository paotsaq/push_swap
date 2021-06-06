/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 05:58:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/06 08:11:38 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void printer(array *array, int sequence)
{
	int i;

	i = -1;
	if (sequence)
	{
		while (++i < array->size)
			printf("%d ", array->stack[i]);
		printf("\n");
	}
	else
	{
		printf("largest\n");
		while (++i < array->size)
			printf("%d ", array->largest_seq_buf[i]);
		printf("\n");
		i = -1;
		printf("pot\n");
		while (++i < array->size)
			printf("%d ", array->pot_seq_buf[i]);
	}
	printf("\n");
}

int	count_ones(char *sequence, int start, int end)
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


static	void merge_sequences(array *array, int *start, int *end)
{
	int i;
	int j;
	int ones;

	if (start)
		i = *start - 1;
	else
		i = -1;
	if (end)
		j = *end;
	else
		j = array->size;

	printer(array, 0);
	ones = count_ones(array->pot_seq_buf, 0, array->count - 1);
	if (ones > array->largest_chain_size)
	{
		while (++i <= j)
			array->largest_seq_buf[i] = array->pot_seq_buf[i];
		array->largest_chain_size = ones;
	}
	ft_bzero(array->pot_seq_buf, array->size);
}

/* checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3) */

/* first call is check_chain_rec(array, 0, 0, 0) */
void	check_chain_rec(array *array, int start, int last, int pos)
{
	array->pot_seq_buf[start] = 1;
	/* if you get to the end of the array,
	 * there were no conflicting chains and thus
	 * the longest chain shall be saved */
	if (start == array->count || pos == array->count)
		merge_sequences(array, NULL, NULL);
	/* a candidate for continuation of the sequence;
	 * checks if the candidate was already in a larger sequence.
	 * otherwise, keep looking forward */
	else if (array->stack[pos] >= array->stack[last])
	{
		array->pot_seq_buf[pos] = 1;
		if (array->largest_seq_buf[pos] == 1)
			merge_sequences(array, &start, &pos);
		else
			check_chain_rec(array, start, pos, pos + 1);
	}
	else
		check_chain_rec(array, start, last, pos + 1);
}

void	run_checks(array *array)
{
	int i;
	int j;

	printer(array, 1);
	i = -1;
	while (++i < array->count)
	{
		j = i - 1;
		while (++j < array->count)
			check_chain_rec(array, i, i, j);
	}
	printer(array, 1);
}
