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

void	do_operations(list_of_arrays *arrays, char *buffer, int parity)
{
	array *main_stack;
	array *other_stack;

	parity += 1;
	main_stack = &arrays->arrays[(arrays->count - 1) % parity];
	other_stack = &arrays->arrays[(arrays->count - 2) % parity];

	if (ft_strcmp(buffer, "s") == 0)
		swap(main_stack);
	else if (ft_strcmp(buffer, "ss") == 0)
		swap_both(main_stack, other_stack);
	else if (ft_strcmp(buffer, "p") == 0)
			push(main_stack, other_stack);
	else if (ft_strcmp(buffer, "r") == 0)
			rotate(main_stack);
	else if (ft_strcmp(buffer, "rr") == 0)
		rotate_both(main_stack, other_stack);
	else if (ft_strcmp(buffer, "revr") == 0)
			reverse_rotate(main_stack);
	else if (ft_strcmp(buffer, "rrr") == 0)
		reverse_rotate_both(main_stack, other_stack);
	visualizer(main_stack, other_stack);
}
