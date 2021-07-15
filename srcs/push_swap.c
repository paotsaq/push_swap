/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 15:53:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	prints_operations(t_stacks *stacks)
{
	int	iter;

	iter = -1;
	while (++iter < stacks->comm_index + 1)
	{
		if (stacks->comm[iter][0] != 'N')
		{
			write(1, stacks->comm[iter], ft_strlen(stacks->comm[iter]));
			write(1, "\n", 1);
		}
	}
}

void	push_swap(t_stacks *stacks)
{
	if (is_sorted(&stacks->array_a))
		return ;
	if (stacks->sorted_size == 3)
		sort_three(stacks);
	else if (stacks->sorted_size == 5)
		sort_five(stacks);
	else
		algorithm(stacks);
	if (stacks->sorted_size > 5)
		sequence_optimizer(stacks);
	prints_operations(stacks);
}
