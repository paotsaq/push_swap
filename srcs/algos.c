/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/12 18:48:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		algorithm(s_stacks *stacks)
{
	int target;
	char direction[5];

	find_lis(stacks);
	while (!(stacks->array_a->count == stacks->lis_size))
		if (element_is_in_lis(stacks, stacks->a[0]))
			do_operations(stacks->array_a, "r", 0);
		else
			do_operations(stacks->array_a, "p", 0);
	while (!(stacks->a_count == stacks->size))
	{
		best_move_interface(stacks);
		update_lis_with_elem(stacks, stacks->a[0]);
	}
	target = pos_in_array(stacks->a, stacks->lis[0], stacks->lis_size);
	if (target < stacks->a_count / 2)
		ft_strlcpy(direction, "r", 5);
	else
		ft_strlcpy(direction, "revr", 5);
	while (!(stacks->a[0] == stacks->lis[0]))
		do_operations(stacks, direction, 0);
}
