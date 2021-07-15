/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:20:43 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 14:57:08 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	print_error(void)
{
	write(1, "Error\n", 7);
	return (-1);
}

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
	int			parity;
	char		buffer[5];

	if (comm[0] == 's')
		ft_strlcpy(buffer, "s", 5);
	else if (comm[0] == 'p')
		ft_strlcpy(buffer, "p", 5);
	else if (comm[0] == 'r' && comm[1] == 'r' && comm[2] != '\0')
		ft_strlcpy(buffer, "revr", 5);
	else
		ft_strlcpy(buffer, "r", 5);
	parity = get_parity(comm);
	if (comm[0] == 'p')
		parity = (parity + 1) % 2;
	if (parity != 2)
		do_operations(stacks, buffer, parity);
	else
	{
		do_operations(stacks, buffer, 0);
		do_operations(stacks, buffer, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*comm;

	initialize_stacks(&stacks);
	if (parsing_of_input(argv, &stacks) == -1)
		return (print_error());
	if (argc == 2)
		return (0);
	while (get_next_line(0, &comm) != 0)
	{
		if (valid_argument(comm))
		{
			apply_operations(&stacks, comm);
			free(comm);
		}
		else
			return (print_error());
	}
	if (is_sorted(&stacks.array_a))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	return (0);
}
