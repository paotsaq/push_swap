/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:44:49 by apinto            #+#    #+#             */
/*   Updated: 2021/05/26 08:00:34 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define A_STACK "%d    \n"
#define B_STACK "    %d\n"
#define STACKS  "%d  %d\n"

void	visualizer(array *stack_a, array *stack_b)
{
	int i;
	int max_stack;
	int min_stack;

	if (stack_a->size > 30)
		printf("gurl you craycray\n")
	else
	{
		max_stack = ft_max(stack_a->count, stack_b->count);
		min_stack = ft_min(stack_a->count, stack_b->count);
		i = max_stack + 1;
		while (--i < max_stack)
		{
			if (max_stack == stack_a->count)
				printf(A_STACK, stack_a->stack[max_stack - 1 - i])
			else
				printf(B_STACK, stack_b->stack[max_stack - 1 - i])
		}
		while (i >= 0)
			printf(STACKS, stack_a->stack[stack_a->count - 1 - i], stack_b->stack[stack_b->count - 1 - i]);
		printf("------\n");
	}
}

void	do_operations(array *stack_a, array *stack_b)
{
	char buffer[4];

	buffer[0] = '\0';
	while(1)
	{
		read(

	}

}
