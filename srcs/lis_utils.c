/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 01:57:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 06:44:30 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

/* if first element, return 0; if last element, return lis_size */
int 	get_corresponding_lis_position(s_stacks *stacks, int elem)
{
	int iter;

	iter = 0;
	while (iter < stacks->lis_size - 1 && stacks->lis[iter] < elem)
		iter++;
	return (iter);
}

int	element_is_in_lis(s_stacks *stacks, int elem)
{
	int	iter;

	iter = -1;
	while (++iter < stacks->lis_size)
		if (stacks->lis[iter] == elem)
			return (1);
	return (0);
}


void	update_lis_with_elem(s_stacks *stacks, int elem)
{
	int stop;
	int iter;

	iter = 0;
	while (stacks->lis[iter] < elem && iter < stacks->lis_size)
		iter++;
	stop = iter;
	iter = stacks->lis_size + 2;
	while (--iter != stop)
		stacks->lis[iter] = stacks->lis[iter - 1];
	stacks->lis[stop] = elem;
	stacks->lis_size++;
	if (stacks->lis_size == stacks->a_count)
		stacks->sorted = 1;
}

int	is_sorted(array *stack)
{
	int iter;

	iter = -1;
	while(++iter < (*stack->count) - 2)
		if (stack->stack[iter] > stack->stack[iter + 1])
			return (0);
	return (1);
}
