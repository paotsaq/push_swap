/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/06/20 16:35:33 by apinto           ###   ########.fr       */
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
	stack->current_range = -1;
	stack->size = size;
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

/* is this still useful? */
void	max_and_min_values(array *stack)
{
	int max;
	int min;

	if (stack->stack)
	{
		max = min = *(stack->stack)++;
		while (stack->stack)
		{
			if (max < *(stack->stack))
				max = *(stack->stack);
			else if (min > *(stack->stack))
				min = *(stack->stack);
			stack->stack++;
		}
		stack->min = min;
		stack->max = max;
	}
}

static int	parsing_of_input(char **argv, list_of_arrays *arrays)
{
	int *begg_stack;
	array *stack;

	stack = &arrays->arrays[0];
	begg_stack = stack->stack;
	stack->count = -1;
	while (*++argv)
		if (ft_content_is_int(*argv) && !is_duplicate(begg_stack, stack->count++, *argv))
			*(stack->stack)++ = atoi(*argv);
		else
		{
			printf("erro muito chato\nnão te esqueças de implementar frees!");
			return (-1);
		}
	stack->stack = begg_stack;
	return (1);
}

int		main(int argc, char **argv)
{
	list_of_arrays arrays;

	if (argc == 1)
		return (0);
	initializes_array(&arrays, 500);
	if (parsing_of_input(argv, &arrays) != -1)
		break_into_lis_algorithm(&arrays);
	else
		printf("I should free some stuff\n");
	return (0);
}
