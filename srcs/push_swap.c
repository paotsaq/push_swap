/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/06/17 08:01:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duplicate(int *stack, int len, char *string)
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

int		main(int argc, char **argv)
{
	array *stack_a;
	array *stack_b;
	int *begg_stack_a;

	if (argc == 1)
		return (1);
	else
	{
		stack_a = calloc(1, sizeof(array));
		stack_b = calloc(1, sizeof(array));
		if (!(stack_a && stack_b))
			return (-1);
		stack_a->stack = calloc(argc - 1, sizeof(int *));
		stack_b->stack = calloc(argc - 1, sizeof(int *));
		if (!(stack_a->stack && stack_b->stack))
			return (-1);
		begg_stack_a = stack_a->stack;
		stack_a->count = 0;
		while (*++argv)
			if (ft_content_is_int(*argv) && !is_duplicate(begg_stack_a, stack_a->count, *argv))
			{
				*(stack_a->stack)++ = atoi(*argv);
				stack_a->count++;
			}
			else
			{
				printf("erro muito chato\nnão te esqueças de implementar frees!");
				return (0);
			}
		stack_a->stack = begg_stack_a;
		stack_b->count = 0;
		stack_a->identity = 'a';
		stack_a->sorted = 0;
		stack_b->sorted = 0;
		stack_b->identity = 'b';
		stack_b->count = 0;
		stack_a->size = argc - 1;
		stack_b->size = argc - 1;
		chain_manager(stack_a);
		new_algo(stack_a, stack_b);
	}
}
