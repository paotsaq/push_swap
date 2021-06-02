/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/06/01 11:42:45 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* clumsily checks for the longest chain of ordered numbers;
 * there might be unsorted numbers in between. This is fine */
int	check_chain(array *array)
{
	int i;
	int iter;
	int max_chain;
	int current_chain;
	int max_starting;
	int starting;

	i = max_starting = max_chain = 0;
	while (i < array->count)
	{
		current_chain = 1
		iter = i + 1;
		starting = array->stack[i];
		while (starting < array->stack[iter++])
			current_chain += 1;
		if (current_chain > max_chain)
		{
			max_chain = current_chain;
			max_starting = starting;
		}
	}
}

/* matches the sorted with the unsorted array
 * and returns the number of elements at their right place.
 * this is useful for very-close-to-sorted arrays! */
int	match_sorted(array *array)
{


}
