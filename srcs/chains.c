
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 05:58:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/09 06:45:25 by apinto           ###   ########.fr       */
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

int		count_ones(char *sequence, int start, int end)
{
	int count;
	int iter;

	count = 0;
	iter = start - 1;
	while (++iter < end)
		if (sequence[iter] == 1)
			count++;
	return (count);
}


static	void merge_sequences(array *array, int *start, int *end)
{
	int i;
	int j;
	int pot_ones;
	int lar_ones;

	if (start)
		i = *start - 1;
	else
		i = -1;
	if (end)
		j = *end;
	else
		j = array->size;

	printer(array, 0);
	pot_ones = count_ones(array->pot_seq_buf, 0, j);
	lar_ones = count_ones(array->largest_seq_buf, 0, j);
	printf("pot ones: %d\nlargest ones: %d\n", pot_ones, lar_ones);
	/* up until to the index *end*, there is a larger sequence in
	 * the potential buffer */
	if (pot_ones > lar_ones)
	{
		while (++i <= j)
			array->largest_seq_buf[i] = array->pot_seq_buf[i];
		if (j == array->count)
			array->largest_chain_size = pot_ones;
		if (start)
			array->start_of_largest_chain = *start;
		else
			array->start_of_largest_chain = 0;

	}
	if (!start && !end)
		ft_bzero(array->pot_seq_buf, array->size);
}

/* checks for the longest chain of ordered numbers;
 * There might be unsorted numbers in between! But this is fine.
 * The algorithm should jump over the unsorted numbers to uncover
 * potentially more rewarding sequences.
 * A buffer might be useful to jump over some specific sequences.
 * A good example is 4 1 5 6 2 3 (longest chain is 4 5 6 2 3) */

/* first call is check_chain_rec(array, 0, 0, 0) */

static	int	get_first_zero_index(array *array, int start)
{
	int iter;

	iter = start;
	while (iter < array->count - 1 && array->largest_seq_buf[iter] != 0)
		iter++;
	return (iter);
}

static void	check_chain_rec(array *array, int start, int last, int pos)
{
	int advance;
	int first_zero;

	advance = -1;
	first_zero = 0;
	/* if you get to the end of the array,
	 * there were no conflicting chains and thus
	 * the longest chain shall be saved */
	if (start >= array->count || pos >= array->count)
		merge_sequences(array, NULL, NULL);
	/* finds a candidate for continuation of the sequence */
	else if (array->stack[pos] > array->stack[last])
	{
		array->pot_seq_buf[pos] = 1;
		/* this will lead to a repeating sequence;
		 * hence, kill this iteration (but merge the sequence,
		 * to determine whether the found sequence so far
		 * is better than the largest) and move on
		 * is merge sequence still useful? */
		if (start == array->start_of_largest_chain && array->largest_seq_buf[pos] == 1)
		{
			merge_sequences(array, &start, &pos);
			first_zero = get_first_zero_index(array, pos);
			/* and then send ALL 1 positions to the first zero next */
			while (pos + ++advance != first_zero)
				check_chain_rec(array, start, pos, pos + advance);
		}
		else
			check_chain_rec(array, start, pos, pos + 1);
	}
	else
		check_chain_rec(array, start, last, pos + 1);
}

int	run_checks(array *array)
{
	int i;
	int j;

	printer(array, 1);
	i = -1;
	array->start_of_largest_chain = -1;
	while (++i < array->count)
	{
		j = i - 1;
		while (++j < array->count)
		{
			array->pot_seq_buf[i] = 1;
			check_chain_rec(array, i, i, j);
			// printer(array, 0);
			ft_bzero(array->pot_seq_buf, array->size);
			if (array->largest_chain_size > array->count - 1)
				return array->largest_chain_size;
		}
	}
	printer(array, 1);
	printer(array, 0);
	return array->largest_chain_size;
}
