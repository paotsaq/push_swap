/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_chains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:27 by apinto            #+#    #+#             */
/*   Updated: 2021/06/10 08:22:45 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* returns an index that signifies the order
 * in which to insert the new node;
 *		-1 means it is smallest among all candidates,
 *			thus create a new list;
 *		chains->count - 1 means it is largest among all candidates,
 *			thus clone the largest list and append it;
 *		any other number signifies the index of the list to append to. */
int finds_localisation_of_node(chains chain, t_list *elem)
{
	t_list a_tail;
	int index;

	a_tail = *tails;
	index = -1;
	while (a_tail)
		if ((int)new_node->content > (int)a_tail->content)
		{
			a_tail = a_tail->next;
			index++;
		}
	return (index);
}

void	creates_list_of_one(chains chain, t_list *elem)
{
	ft_lstadd_front(chain->heads, elem);
	ft_lstadd_front(chain->tails, elem);
	if (chain->sizes++ == 0)
		chain->largest_active = 1;
}

void	clones_list(chains chain, t_list **list_to_clone)
{
	t_list **new_list;
	t_list *begg_new_list;

	new_list = malloc(sizeof(t_list **));
	if (!new_list)
		return;
	begg_new_list = *new_list;
	while (*list_to_clone)
	{
		*new_list = lst_new(*(list_to_clone)->content);
		if (!(*new_list))
			ft_lstclear(begg_new_list);
		(*list_to_clone) = (*list_to_clone)->next;
	}
	return (begg_new_list);
}

void	adds_extended_list(chains chain, t_list *elem, int index)
{
	t_list **list;
	t_list **new_list;
	t_list *begg_new_list;

	if (index == chain->count -1)
		list = chain->largest_active;
	else
	{
		list = chain->heads;
		while (*list && index-- != 0)
			*list = *(list)->next;
	}
	*new_list = clones_list(*list);
	if (!(*new_list))
		return;
	ft_lstadd_back(*new_list
}


void chain_manager(array *stack)
{
	chains chain;
	int index;

	while (++iter < stack->count)
	{
		elem = ft_lstnew(stack->array[iter]);
		index = finds_localisation_of_node(chain, elem);
		if (index == 1)
			creates_list_of_one(chain, elem);
		else if (index == chain->count - 1)

	}
}
