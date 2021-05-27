/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:44:49 by apinto            #+#    #+#             */
/*   Updated: 2021/05/26 10:21:35 by apinto           ###   ########.fr       */
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
		printf("gurl you craycray\n");
	else
	{
		max_stack = ft_max(2, stack_a->count, stack_b->count);
		min_stack = ft_min(2, stack_a->count, stack_b->count);
		i = max_stack + 1;
		while (--i <= max_stack && i > min_stack)
		{
			if (max_stack == stack_a->count)
				printf(A_STACK, stack_a->stack[max_stack - i]);
			else
				printf(B_STACK, stack_b->stack[max_stack - i]);
		}
		while (i-- >= 1)
			printf(STACKS, stack_a->stack[stack_a->count - 1 - i], stack_b->stack[stack_b->count - 1 - i]);
		printf("------\n");
	}
}

void	do_operations(array *stack_a, array *stack_b)
{
	char buffer[4];
	int i;

	while(1)
	{
		visualizer(stack_a, stack_b);
		ft_bzero(buffer, 4);
		read(0, &buffer, 4);
		i = 0;
		while (buffer[i]  && buffer[i] != '\n')
			i++;
		buffer[i] = '\0';
		if (ft_strcmp(buffer, "sa") == 0)
			swap(stack_a);
		else if (ft_strcmp(buffer, "sb") == 0)
			swap(stack_b);
		else if (ft_strcmp(buffer, "ss") == 0)
			swap_both(stack_a, stack_b);
		else if (ft_strcmp(buffer, "pa") == 0)
			push(stack_a, stack_b);
		else if (ft_strcmp(buffer, "pb") == 0)
			push(stack_b, stack_a);
		else if (ft_strcmp(buffer, "ra") == 0)
			rotate(stack_a);
		else if (ft_strcmp(buffer, "rb") == 0)
			rotate(stack_b);
		else if (ft_strcmp(buffer, "rr") == 0)
			rotate_both(stack_a, stack_b);
		else if (ft_strcmp(buffer, "rra") == 0)
			reverse_rotate(stack_a);
		else if (ft_strcmp(buffer, "rrb") == 0)
			reverse_rotate(stack_b);
		else if (ft_strcmp(buffer, "rrr") == 0)
			reverse_rotate_both(stack_a, stack_b);
	}
}
