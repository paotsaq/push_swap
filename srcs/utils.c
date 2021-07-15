/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 15:49:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stacks(t_stacks *stacks)
{
	stacks->sorted = 0;
	stacks->comm_index = -1;
	stacks->size = 500;
	stacks->a_count = 0;
	stacks->sorted_size = 0;
	stacks->b_count = 0;
	stacks->array_a.stack = stacks->a;
	stacks->array_a.count = &stacks->a_count;
	stacks->array_a.size = &stacks->size;
	stacks->array_b.stack = stacks->b;
	stacks->array_b.count = &stacks->b_count;
	stacks->array_b.size = &stacks->size;
}

int	pos_in_array(int *array, int elem, int limit)
{
	int	iter;

	iter = 0;
	while (iter < limit - 1 && array[iter] != elem)
		iter++;
	return (iter);
}

int	is_sorted(t_array *stack)
{
	int	iter;

	iter = -1;
	if (*stack->count < 2)
		return (1);
	while (++iter < *stack->count - 1)
		if (stack->stack[iter] > stack->stack[iter + 1])
			return (0);
	return (1);
}

int	find_index_by_size(t_chains *chain, int size)
{
	int	res;

	res = 0;
	while (chain->sizes[res] != size)
		res++;
	return (res);
}

int	get_elem_position_in_stack(t_stacks *stacks, int elem)
{
	int	iter;

	iter = 0;
	while (iter < stacks->lis_size - 1 && stacks->a[iter] != elem)
		iter++;
	return (iter);
}
