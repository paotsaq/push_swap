/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/10 17:57:12 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

chains	*initializes_chain()
{
	chains *chain;

	chain = malloc(sizeof(chains));
	if (!chain)
		return NULL;
	chain->count = 0;
	return chain;
}

void			free_list_node(void *list_node)
{
	t_list *list;

	list = (t_list *)list_node;
	free(list->content);
	free(list);
}

/* returns an index that signifies the list
 * in which to insert the new node;
 *		-1 means it is smallest among all candidates,
 *			thus create a new list;
 *		chains->count - 1 means it is largest among all candidates,
 *			thus clone the largest list and append it;
 *		any other number signifies the index of the list to append to. */
int finds_localisation_of_node(chains *chain, t_list *elem)
{
	t_list *a_tail;
	int index;

	if (chain->count == 0)
		return (-1);
	a_tail = *chain->tails;
	index = -1;
	while (a_tail)
	{
		if ((int)elem->content > (int)a_tail->content)
			index++;
		a_tail = a_tail->next;
	}
	return (index);
}

/* manages adding of the size information to the chain */ 
void	adds_size(chains *chain, int size, int front)
{
	t_list *new_size_node;

	new_size_node = ft_lstnew(&size);
	if (!(new_size_node))
		return;
	if (chain->count++ == 0)
	{
		chain->sizes = &new_size_node;
		return;
	}
	if (front)
		ft_lstadd_front(chain->sizes, new_size_node);
	else
		ft_lstadd_back(chain->sizes, new_size_node);
}

/* creates a list of just one element 
 * and appends it to the chains */
void	creates_list_of_one(chains *chain, t_list *elem)
{
	if (chain->count == 0)
	{
		chain->heads = &elem;
		chain->tails = &elem;
	}
	else
	{
		ft_lstadd_front(chain->heads, elem);
		ft_lstadd_front(chain->tails, elem);
	}
	if (chain->sizes++ == 0)
		chain->largest_active = chain->heads;
	adds_size(chain, 1, 1);
}


/* creates a clone of a list, and appends the new elem to it.
 * it will then append it to the chains; */
void	adds_extended_list(chains *chain, t_list *elem, int index)
{
	t_list **list;
	t_list **new_list;
	t_list *size_node;

	if (index == chain->count -1)
		list = chain->largest_active;
	else
	{
		list = chain->heads;
		size_node = *(chain)->sizes;
		while (index-- != 0)
		{
			size_node = size_node->next; 
			*list = (*list)->next;
		}
	}
	new_list = ft_lstclone(list);
	if (!(new_list))
		return;
	ft_lstadd_back(new_list, elem);
	ft_lstadd_back(chain->heads, *new_list);
	ft_lstadd_back(chain->tails, elem);
	adds_size(chain, (int)size_node->content + 1, 0);
	if (index == -1)
		chain->largest_active = new_list;
	chain->count++;
}

void chain_manager(array *stack)
{
	t_list *elem;
	chains *chain;
	int index;
	int iter;

	chain = initializes_chain();
	if (!chain)
		return;
	iter = -1;
	while (++iter < stack->count)
	{
		elem = ft_lstnew(&stack->stack[iter]);
		if (!elem)
		{
			ft_lstclear(chain->heads, &free_list_node);
			ft_lstclear(chain->tails, &free_list_node);
			ft_lstclear(chain->sizes, &free_list_node);
		}
		index = finds_localisation_of_node(chain, elem);
		if (index == -1)
			creates_list_of_one(chain, elem);
		else
			adds_extended_list(chain, elem, index);
	}
}
