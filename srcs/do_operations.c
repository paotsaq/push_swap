/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:29:59 by apinto            #+#    #+#             */
/*   Updated: 2021/06/20 07:18:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_operations(array *stack_a, array *stack_b, char *buffer)
{
	if (ft_strcmp(buffer, "s") == 0)
	{
		if (stack_a->identity % 2 == 0)
			swap(stack_a);
		else
			swap(stack_b);
	}
	else if (ft_strcmp(buffer, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(buffer, "p") == 0)
	{
		if (stack_a->identity % 2 == 0)
			push(stack_a, stack_b);
		else
			push(stack_b, stack_a);
	}
	else if (ft_strcmp(buffer, "r") == 0)
	{
		if (stack_a->identity % 2 == 0)
			rotate(stack_a);
		else
			rotate(stack_b);
	}
	else if (ft_strcmp(buffer, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(buffer, "revr") == 0)
	{
		if (stack_a->identity % 2 == 0)
			reverse_rotate(stack_a);
		else
			reverse_rotate(stack_b);
	}
	else if (ft_strcmp(buffer, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
	visualizer(stack_a, stack_b);
}
