/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/05/27 12:55:32 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	main(int argc, char **argv)
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
		while (*++argv)
			if (ft_content_is_int(*argv))
				*(stack_a->stack)++ = atoi(*argv);
		stack_a->stack = begg_stack_a;
		stack_a->count = argc - 1;
		stack_b->count = 0;
		stack_a->size = argc - 1;
		stack_b->size = argc - 1;
		algo(stack_a, NULL);
		// do_operations(stack_a, stack_b);
	}
}
