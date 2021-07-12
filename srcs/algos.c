/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/12 08:30:38 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		algorithm(stacks_struct *stacks)
{
	int target;
	char direction[5];

	initializes_array(arrays, 500);
	find_lis(stacks);
	while (!(this_stack->count == this_stack->lis_size))
		if (element_is_in_lis(this_stack, this_stack->stack[0]))
			do_operations(arrays, "r", 0);
		else
			do_operations(arrays, "p", 0);
	while (!(this_stack->count == arrays->sorted_size))
	{
		best_move_interface(arrays);
		update_lis_with_elem(this_stack, this_stack->stack[0]);
	}
	target = get_elem_position_in_stack(this_stack, this_stack->lis[0]);
	if (target < this_stack->count / 2)
		ft_strlcpy(direction, "r", 5);
	else
		ft_strlcpy(direction, "revr", 5);
	while (!(this_stack->stack[0] == this_stack->lis[0]))
		do_operations(arrays, direction, 0);
}
