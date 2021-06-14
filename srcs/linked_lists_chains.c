/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/14 09:55:59 by apinto           ###   ########.fr       */
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

	iter = 0;
	while (iter < chain->count && elem > chain->tails[iter])
		iter++;
	return (iter);
}

/* updates the size array and handles
 * determining which is the largest sequence */
void	size_and_largest_sequence(chains *chain, int index, int size)
{
	chain->sizes[index] = size;
	if (size >= chain->largest_size)
	{
		chain->largest_active = chain->heads[index];
		chain->largest_size = size;
	}
}

/* creates a list of just one element and
 * adds the size to the chain.*/
void	copies_new_largest_list(int *deprc_list, int *new_list, int size)
{
	int i;
	i = -1;
	if (new_list != NULL)
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
		size += 1;
	}
	/* there was an index; take the corresponding list
	 * and substitute last value */
	else
	{
		// index = index - 1;
		list = chain->heads[index];
		size = chain->sizes[index];
		list[size - 1] = elem;
	}
	chain->tails[index] = elem;
	size_and_largest_sequence(chain, index, size);
}

void chain_manager(array *stack)
{
	chains chain;
	int index;
	int iter;
	int elem;

	chain.count = 0;
	chain.largest_size = 0;
	chain.largest_active = NULL;
	iter = -1;
	while (++iter < stack->count)
	{
		elem = stack->stack[iter];
		index = finds_localisation_of_node(&chain, elem);
		extends_list(&chain, elem, index);
	}
	printf("longest sequence is: \n");
	iter = -1;
	while (++iter < chain.largest_size)
		printf("%d ", chain.largest_active[iter]);
	printf("\n");
}
