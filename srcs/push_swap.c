/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/07/06 07:07:13 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initializes_array(list_of_arrays *arrays, int size)
{
	array *stack;

	stack = &arrays->arrays[arrays->count];
	stack->count = 0;
	stack->identity = arrays->count;
	stack->sorted = 0;
	stack->lis_index = -1;
	stack->size = size;
	stack->orientation = 0;
	stack->pending_lis = 0;
	arrays->count += 1;
}

static int	is_duplicate(int *stack, int len, char *string)
{
	int number;
	int iter;

	number = ft_atoi(string);
	iter = -1;
	while (++iter < len)
		if (stack[iter] == number)
			return (1);
	return (0);
}

static int	parsing_of_input(char **argv, list_of_arrays *arrays)
{
	int i;
	array *stack;

	stack = &arrays->arrays[0];
	stack->count = 0;
	i = -1;
	while (*++argv)
		if (ft_content_is_int(*argv) && !is_duplicate(stack->stack, stack->count++, *argv))
			stack->stack[++i] = atoi(*argv);
		else
		{
			printf("erro muito chato\nnão te esqueças de implementar frees!");
			return (-1);
		}
	return (1);
}

int		main(int argc, char **argv)
{
	list_of_arrays arrays;

	if (argc == 1)
		return (0);
	arrays.count = 0;
	initializes_array(&arrays, 500);
	if (parsing_of_input(argv, &arrays) != -1)
		break_into_lis_algorithm(&arrays);
	else
		printf("I should free some stuff\n");
	return (0);
}
