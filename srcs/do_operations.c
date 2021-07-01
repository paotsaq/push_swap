/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:29:59 by apinto            #+#    #+#             */
/*   Updated: 2021/07/01 18:22:18 by apinto           ###   ########.fr       */
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

	initialize_stacks(arrays, &main_stack, &other_stack, parity);
	if (ft_strcmp(buffer, "s") == 0)
		write(1, "s", 1);
	else if (ft_strcmp(buffer, "ss") == 0)
	{
		write(1, "ss\n", 3);
		return;
	}
	else if (ft_strcmp(buffer, "p") == 0)
		write(1, "p", 1);
	else if (ft_strcmp(buffer, "r") == 0)
		write(1, "r", 1);
	else if (ft_strcmp(buffer, "rr") == 0)
	{
		write(1, "rr\n", 3);
		return;
	}
	else if (ft_strcmp(buffer, "revr") == 0)
		write(1, "rr", 2);
	else if (ft_strcmp(buffer, "rrr") == 0)
	{
		write(1, "rrr\n", 3);
		return;
	}
	if ((arrays->count + parity) % 2 == 0 && buffer[0] == 'p')
		write(1, "b\n", 2);
	else if ((arrays->count + parity) % 2 == 1 && buffer[0] == 'p')
		write(1, "a\n", 2);
	else if ((arrays->count + parity) % 2 == 0)
		write(1, "a\n", 2);
	else
		write(1, "b\n", 2);
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
	// visualizer(&arrays->arrays[arrays->count - 2], &arrays->arrays[arrays->count - 1]);
}
