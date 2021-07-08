/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:29:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/08 14:56:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void initialize_stacks(list_of_arrays *arrays, array **main, array **other, int parity)
{
	if (!parity)
	{
		*main = &arrays->arrays[arrays->count - 2];
		*other = &arrays->arrays[arrays->count - 1];
	}
	else
	{
		*other = &arrays->arrays[arrays->count - 2];
		*main = &arrays->arrays[arrays->count - 1];
	}
}

static void	print_operations(list_of_arrays *arrays, char *buffer, int parity)
{
	array *main_stack;
	array *other_stack;
	char *cell;

	cell = arrays->comm[++arrays->comm_index];
	initialize_stacks(arrays, &main_stack, &other_stack, parity);
	if (ft_strcmp(buffer, "s") == 0)
		cell[0] = 's';
	else if (ft_strcmp(buffer, "p") == 0)
		cell[0] = 'p';
	else if (ft_strcmp(buffer, "r") == 0)
		cell[0] = 'r';
	else if (ft_strcmp(buffer, "revr") == 0)
		ft_strlcpy(cell, "rr", 3);
	if ((arrays->count + parity) % 2 == 0 && buffer[0] == 'p')
		cell[1] = 'b';
	else if ((arrays->count + parity) % 2 == 1 && buffer[0] == 'p')
		cell[1] = 'a';
	else if ((arrays->count + parity) % 2 == 0)
		cell[1] = 'a';
	else
		cell[1] = 'b';
}

void	do_operations(list_of_arrays *arrays, char *buffer, int parity)
{
	array *main_stack;
	array *other_stack;

	initialize_stacks(arrays, &main_stack, &other_stack, parity);
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
	print_operations(arrays, buffer, parity);
	visualizer(&arrays->arrays[arrays->count - 2], &arrays->arrays[arrays->count - 1]);
}
