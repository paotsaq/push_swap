/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:29:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 03:28:09 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_both_stacks(t_stacks *stacks,
			t_array **main, t_array **other, int parity)
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

static void	store_operations(t_stacks *stacks, char *buffer, int parity)
{
	t_array	*main_stack;
	t_array	*other_stack;
	char	*cell;

	cell = stacks->comm[++stacks->comm_index];
	ft_bzero(cell, 5);
	initialize_both_stacks(stacks, &main_stack, &other_stack, parity);
	if (ft_strcmp(buffer, "s") == 0)
		cell[0] = 's';
	else if (ft_strcmp(buffer, "p") == 0)
		cell[0] = 'p';
	else if (ft_strcmp(buffer, "r") == 0)
		cell[0] = 'r';
	else if (ft_strcmp(buffer, "revr") == 0)
		ft_strlcpy(cell, "rr", 5);
	if (parity % 2 == 0 && buffer[0] == 'p')
		ft_strlcat(&cell[0], "b", 5);
	else if (parity % 2 == 1 && buffer[0] == 'p')
		ft_strlcat(&cell[0], "a", 5);
	else if (parity % 2 == 0)
		ft_strlcat(&cell[0], "a", 5);
	else
		ft_strlcat(&cell[0], "b", 5);
}

void	do_operations(t_stacks *stacks, char *buffer, int parity)
{
	t_array	*main_stack;
	t_array	*other_stack;

	initialize_both_stacks(stacks, &main_stack, &other_stack, parity);
	if (ft_strcmp(buffer, "s") == 0)
		swap(main_stack);
	else if (ft_strcmp(buffer, "p") == 0)
		push(main_stack, other_stack);
	else if (ft_strcmp(buffer, "r") == 0)
		rotate(main_stack);
	else if (ft_strcmp(buffer, "revr") == 0)
		reverse_rotate(main_stack);
	store_operations(stacks, buffer, parity);
}
