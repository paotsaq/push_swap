/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/07/10 18:17:47 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* returns an index that signifies the list
 * in which to insert the new node;
*		0 means it is smallest among all candidates,
*			thus create a new list;
*		chains->count means it is largest among all candidates,
*			thus clone the largest list and append it;
*		any other number signifies the index of the list to append to. */
static int	finds_localisation_of_node(chains *chain, int elem)
{
	int	iter;

	iter = 0;
	while (iter < chain->count && elem > chain->tails[iter])
		iter++;
	return (iter);
}

/* updates the size array and handles
 * determining which is the largest sequence */
static void	size_and_largest_sequence(chains *chain, int index, int size)
{
	chain->sizes[index] = size;
	if (size >= chain->largest_size)
	{
		chain->largest_active = chain->heads[index];
		chain->largest_size = size;
	}
}

/* static int	find_index_by_size(chains *chain, int size)
{
	int	res;

	res = 0;
	while (chain->sizes[res] != size)
		res++;
	return (res);
} */


/* adds the size to the chain, and triggers deprecated sequences
 * new_list should be statically allocated outside of the chain and then added; 
 * this avoids redundant copies of the same list in the chain */
static void	extends_list(chains *chain, int elem, int index)
{
	int	*new_list;
	int	*list;
	int	size;
	int	copy_from;

	if (index == chain->count)
	{
		list = chain->largest_active;
		size = chain->largest_size + 1;
		new_list = chain->heads[chain->count];
		chain->count += 1;
	}
	else
	{
		new_list = chain->heads[index];
		size = chain->sizes[index];
		copy_from = pos_in_array(chain->sizes, size, 500);
//		copy_from = find_index_by_size(chain, size - 1);
		list = chain->heads[copy_from];
	}
	new_list[size - 1] = elem;
	ft_memcpy(new_list, list, 4 * (size - 1));
	// copies_new_largest_list(list, new_list, size - 1);
	chain->tails[index] = elem;
	size_and_largest_sequence(chain, index, size);
}

static void	initializes_chain(chains *chain)
{
	chain->largest_size = 0;
	chain->largest_active = NULL;
	chain->count = 0;
}
void	find_lis(s_stacks *stacks)
{
	chains	chain;
	int		rotation;
	int		iter;
	int		index;

	rotation = -1;
	while (++rotation < stacks->a_count)
	{
		initializes_chain(&chain);
		iter = -1;
		while (++iter < stacks->a_count)
		{
			index = finds_localisation_of_node(&chain, stacks->a[iter]);
			extends_list(&chain, stacks->a[iter], index);
		}
		if (chain.largest_size > stacks->lis_size)
		{
			ft_memcpy(stacks->lis, chain.largest_active, 4 * chain.largest_size);
			stacks->lis_size = chain.largest_size;
		}
		rotate(&stacks->array_a);
	}
}
