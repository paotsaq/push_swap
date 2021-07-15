/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:20:43 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 03:51:48 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	valid_argument(char *arg)
{
	return (arg != NULL && (
		ft_strcmp(arg, "sa") == 0
		|| ft_strcmp(arg, "sb") == 0
		|| ft_strcmp(arg, "ss") == 0
		|| ft_strcmp(arg, "pa") == 0
		|| ft_strcmp(arg, "pb") == 0
		|| ft_strcmp(arg, "ra") == 0
		|| ft_strcmp(arg, "rb") == 0
		|| ft_strcmp(arg, "rr") == 0
		|| ft_strcmp(arg, "rra") == 0
		|| ft_strcmp(arg, "rrb") == 0
		|| ft_strcmp(arg, "rrr") == 0));
}

static int	get_parity(char *comm)
{
	if (comm[ft_strlen(comm) - 1] == 'a')
		return (0);
	else if (comm[ft_strlen(comm) - 1] == 'b')
		return (1);
	else
		return (2);
}

static void	apply_operations(t_stacks *stacks, char *comm)
{
	int			iter;
	int			parity;
	char		buffer[5];

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		if (comm[0] == 's')
			ft_strlcpy(buffer, "s", 5);
		else if (comm[0] == 'p')
			ft_strlcpy(buffer, "p", 5);
		else if (comm[0] == 'r'
				&& comm[1] != 'r')
			ft_strlcpy(buffer, "r", 5);
		else
			ft_strlcpy(buffer, "revr", 5);
		parity = get_parity(comm);
		if (parity != 2)
			do_operations(stacks, buffer, parity);
		else
		{
			do_operations(stacks, buffer, 0);
			do_operations(stacks, buffer, 1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*comm;

	if (argc == 2)
		return (0);
	initialize_stacks(&stacks);
	if (parsing_of_input(argv, &stacks) == -1)
	{
		write(1, "Error\n", 7);
		return (-1);
	}
	push_swap(&stacks);
	while (get_next_line(1, &comm))
		if (valid_argument(comm))
			apply_operations(&stacks, comm);
		else
		{
			write(1, "Error\n", 7);
			return (-1);
		}
	if (is_sorted(&stacks.array_a) && stacks.array_b.count == 0)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	return (0);
}
