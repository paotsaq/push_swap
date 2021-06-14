/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/14 06:08:51 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* returns an index that signifies the list
 * in which to insert the new node;
 *		-1 means it is smallest among all candidates,
 *			thus create a new list;
 *		chains->count - 1 means it is largest among all candidates,
 *			thus clone the largest list and append it;
 *		any other number signifies the index of the list to append to. */
int		finds_localisation_of_node(chains *chain, int elem)
{
	int iter;

	if (chain->count == 0)
		return (-1);
	iter = 0;
	while (iter < chain->count && elem > chain->tails[iter])
		iter++;
	return (iter);
}

/* updates the size array and handles
 * determining which is the largest sequence */
void	size_and_largest_sequence(chains *chain, int size, int *list)
{
	chain->sizes[chain->count] = size;
	if (size >= chain->largest_size)
	{
		chain->largest_active = list;
		chain->largest_size = size;
	}
}

/* creates a list of just one element and
 * adds the size to the chain.*/
void	creates_list_of_one(chains *chain, int elem)
{
	chain->heads[chain->count][0] = elem;
	chain->tails[chain->count] = elem;
	size_and_largest_sequence(chain, 1, chain->heads[chain->count]);
}

void	copies_new_largest_list(int *deprc_list, int *new_list, int size)
{
	int i;
	i = -1;
	while (++i < size)
		deprc_list[i] = new_list[i];
}

void	deletes_redundant_list(int *deprc_list, int size)
{
	int i;
	i = -1;
	while (++i < size)
		deprc_list[i] = 0;
}

void	removes_deprecated_sequences(chains *chain, int size)
{
	int iter;
	int copied;
	int last_list_size;
	int *deprc_list;
	int *last_list;

	iter = -1;
	copied = 0;
	while (++iter < chain->count)
	{
		if (chain->sizes[iter] == size)
		{
			deprc_list = chain->heads[iter];
			last_list = chain->heads[chain->count];
			last_list_size = chain->sizes[chain->count];
			if (copied == 0)
				copies_new_largest_list(deprc_list, last_list, last_list_size);
			else
				deletes_redundant_list(deprc_list
			chain->sizes[iter] = last_list_size;
			chain->tails[iter] = last_list[last_list_size - 1];
			iter--;
			chain->count--;
			copied = 1;
		}
	}
}

/* creates a clone of a list, and appends the new elem to it.
 * adds the size to the chain, and triggers deprecated sequences */
void	extends_list(chains *chain, int elem, int index)
{
	int *list;
	int *new_list;
	int size;

	/* the element is bigger than all tails;
	 * thus, append to clone of largest active list */
	if (index == chain->count)
	{
		list = chain->largest_active;
		size = chain->largest_size;
	}
	/* there was an index; take the corresponding list
	 * and substitute last value */
	else
	{
		list = chain->heads[index];
		size = chain->sizes[index] - 1;
	}
	new_list = chain->heads[chain->count];
	ft_memcpy(new_list, list, chain->sizes[size - 1]);
	new_list[size] = elem;
	chain->tails[chain->count] = elem;
	size_and_largest_sequence(chain, size + 1, new_list);
	removes_deprecated_sequences(chain, size + 1);
}

void chain_manager(array *stack)
{
	chains chain;
	int index;
	int iter;
	int elem;

	chain.count = 0;
	chain.largest_size = 0;
	iter = -1;
	while (++iter < stack->count)
	{
		elem = stack->stack[iter];
		index = finds_localisation_of_node(&chain, elem);
		if (index == -1)
			creates_list_of_one(&chain, elem);
		else
			extends_list(&chain, elem, index);
		chain.count += 1;
	}
}
