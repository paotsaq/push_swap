/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/17 07:21:10 by apinto           ###   ########.fr       */
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

void	copies_new_largest_list(int *old_list, int *new_list, int size)
{
	int i;
	i = -1;
	if (old_list != NULL && old_list != new_list)
		while (++i < size)
			new_list[i] = old_list[i];
}

int	find_index_by_size(chains *chain, int size)
{
	int res;

	res = 0;
	while (chain->sizes[res] != size)
		res++;
	return res;
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
	int copy_from;

	/* the element is bigger than all tails;
	 * thus, append to clone of largest active list */
	if (index == chain->count)
	{
		list = chain->largest_active;
		size = chain->largest_size + 1;
		new_list = chain->heads[chain->count];
		chain->count += 1;
	}
	/* this will not be a maximum list so find index of list (deprc list)
	 * whose end element is bigger than current elem;
	 * then, clone and extend the list whose size is
	 * one unit less than the deprc list with elem,
	 * and overwrite deprc list */
	else
	{
		new_list = chain->heads[index];
		size = chain->sizes[index];
		copy_from = find_index_by_size(chain, size - 1);
		list = chain->heads[copy_from];
	}
	new_list[size - 1] = elem;
	copies_new_largest_list(list, new_list, size - 1);
	chain->tails[index] = elem;
	size_and_largest_sequence(chain, index, size);
}

void chain_manager(array *stack)
{
	chains chain;
	int	rotation;
	int index;
	int iter;
	int elem;

	rotation = -1;
	chain.really_largest_active = NULL;
	chain.really_largest_size = 0;
	while (++rotation < stack->count)
	{
		chain.largest_size = 0;
		chain.largest_active = NULL;
		chain.count = 0;
		iter = -1;
		while (++iter < stack->count)
		{
			elem = stack->stack[iter];
			index = finds_localisation_of_node(&chain, elem);
			extends_list(&chain, elem, index);
		}
		if (chain.largest_size > stack->lis_size)
		{
			stack->lis = chain.largest_active;
			stack->lis_size = chain.largest_size;
			stack->lis_rotations = rotation;
		}
		rotate(stack);
	}
	printf("longest sequence is: \n");
	iter = -1;
	while (++iter < stack->lis_size)
		printf("%d ", stack->lis[iter]);
	printf("\n%d elements long\n", stack->lis_size);
}
