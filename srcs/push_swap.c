/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/07/12 08:25:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* must use strncpy! 🚨 */
static void	prints_operations(stacks_struct *stacks)
{
	int	iter;

	iter = -1;
	while (++iter < stacks.comm_index)
		write(1, stacks.comm[iter], 5);
}

static void	initializes_stacks(stacks_struct *stacks)
{
	stacks->sorted = 0;
	stacks->size = 500;
	stacks->a_count = 0;
	stacks->b_count = 0;
}

static int	is_duplicate(int *stack, int len, char *string)
{
	int	number;
	int	iter;

	number = ft_atoi(string);
	iter = -1;
	while (++iter < len)
		if (stack[iter] == number)
			return (1);
	return (0);
}

static int	parsing_of_input(char **argv, stacks_struct *stacks)
{
	int		i;
	array	*stack;

	stack = &stacks->a;
	stacks->a_count = 0;
	i = -1;
	while (*++argv)
		if (ft_content_is_int(*argv)
			&& !is_duplicate(stacks->a, stacks->a_count++, *argv))
			stacks->a[++i] = atoi(*argv);
	else
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	stacks_struct	stacks;
	int				iter;

	if (argc == 2)
		return (0);
	initializes_stacks(&stacks, 500);
	if (parsing_of_input(argv, &stacks) != -1)
	/*
	 * if (stacks.size == 3)
	 *		use another algorithm;
	 *	else */
		algorithm(&stacks);
	else
		write(1, "Error\n", 7);
	// optimizer
	prints_operations(&stacks);
	return (0);
}
