/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 08:17:51 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* must use strncpy! 🚨 */
static void	prints_operations(s_stacks *stacks)
{
	int	iter;

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		write(1, stacks->comm[iter], ft_strlen(stacks->comm[iter]));
		write(1, "\n", 1);
	}
}

static void	initializes_stacks(s_stacks *stacks)
{
	stacks->sorted = 0;
	stacks->comm_index = -1;
	stacks->size = 500;
	stacks->a_count = 0;
	stacks->b_count = 0;
	stacks->array_a.stack = stacks->a;
	stacks->array_a.count = &stacks->a_count;
	stacks->array_a.size = &stacks->size;
	stacks->array_b.stack = stacks->b;
	stacks->array_b.count = &stacks->b_count;
	stacks->array_b.size = &stacks->size;
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

static int	parsing_of_input(char **argv, s_stacks *stacks)
{
	int		i;

	stacks->a_count = 0;
	i = -1;
	while (*++argv)
		if (ft_content_is_int(*argv)
			&& !is_duplicate(stacks->a, stacks->a_count++, *argv))
			stacks->a[++i] = atoi(*argv);
	else
		return (-1);
	stacks->sorted_size = i + 1;
	return (1);
}

int	main(int argc, char **argv)
{
	s_stacks	stacks;

	if (argc == 2)
		return (0);
	initializes_stacks(&stacks);
	if (parsing_of_input(argv, &stacks) != -1)
	{
		if (stacks.size == 3)
	 		sort_three(&stacks);
	 	else if (stacks.size == 5)
	 		sort_five(&stacks);
		else
			algorithm(&stacks);
	}
	else
		write(1, "Error\n", 7);
	// optimizer
	prints_operations(&stacks);
	return (0);
}
