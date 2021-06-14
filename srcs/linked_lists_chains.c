/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/14 06:48:26 by apinto           ###   ########.fr       */
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
 * adds the size to the chain.
 * ⚠️  possibly unnecessary function ⚠️  */
void	creates_list_of_one(chains *chain, int elem)
{
	chain->heads[chain->count][0] = elem;
	chain->tails[chain->count] = elem;
	size_and_largest_sequence(chain, 1, chain->heads[chain->count]);
	chain->count += 1;
}

/* creates a list of just one element and
 * adds the size to the chain.*/
void	copies_new_largest_list(int *deprc_list, int *new_list, int size)
{
	int i;
	i = -1;
	while (++i < size)
		deprc_list[i] = new_list[i];
}

/*
 * adds the size to the chain, and triggers deprecated sequences
 * new_list should be statically allocated outside of the chain
 * and then added; this avoids redundant copies of the same list in the chain */
void	extends_list(chains *chain, int elem, int index)
{
	int *new_list;
	int *list;
	int size;

	/* the element is bigger than all tails;
	 * thus, append to clone of largest active list */
	if (index == chain->count)
	{
		list = chain->largest_active;
		size = chain->largest_size;
		new_list = chain->heads[chain->count];
		copies_new_largest_list(new_list, list, chain->sizes[size - 1]);
		new_list[size] = elem;
		chain->count += 1;
	}
	/* there was an index; take the corresponding list
	 * and substitute last value */
	else
	{
		list = chain->heads[index];
		size = chain->sizes[index] - 1;
		list[size] = elem;
		chain->tails[index] = elem;
		if (size == chain->largest_size)
			chain->largest_active = list;
	}
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
	}
}
