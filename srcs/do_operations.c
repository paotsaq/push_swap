/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:29:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 06:40:26 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_stacks(s_stacks *stacks,
			array **main, array **other, int parity)
{
	if (!parity)
	{
		*main = &stacks->array_a;
		*other = &stacks->array_b;
	}
	else
	{
		*main = &stacks->array_b;
		*other = &stacks->array_a;
	}
}

static void	print_operations(s_stacks *stacks, char *buffer, int parity)
{
	array	*main_stack;
	array	*other_stack;
	char	*cell;

	cell = stacks->comm[++stacks->comm_index];
	initialize_stacks(stacks, &main_stack, &other_stack, parity);
	if (ft_strcmp(buffer, "s") == 0)
		cell[0] = 's';
	else if (ft_strcmp(buffer, "p") == 0)
		cell[0] = 'p';
	else if (ft_strcmp(buffer, "r") == 0)
		cell[0] = 'r';
	else if (ft_strcmp(buffer, "revr") == 0)
		ft_strlcpy(cell, "rr", 5);
	if (parity % 2 == 0 && buffer[0] == 'p')
		ft_strlcat(&cell[1], "b", 5);
	else if (parity % 2 == 1 && buffer[0] == 'p')
		ft_strlcat(&cell[1], "a", 5);
	else if (parity % 2 == 0)
		ft_strlcat(&cell[1], "a", 5);
	else
		ft_strlcat(&cell[1], "b", 5);
}

void	do_operations(s_stacks *stacks, char *buffer, int parity)
{
	array	*main_stack;
	array	*other_stack;

	initialize_stacks(stacks, &main_stack, &other_stack, parity);
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
	print_operations(stacks, buffer, parity);
}
