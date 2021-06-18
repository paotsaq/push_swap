/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:44:49 by apinto            #+#    #+#             */
/*   Updated: 2021/06/17 20:46:35 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

#define A_STACK "%2d    \n"
#define B_STACK "    %2d\n"
#define STACKS  "%2d   %2d\n"

void	prints_array(int *array, int size)
{
	int i;

	printf("content of the array is: \n");
	i = -1;
	while (++i < size)
		printf("%d ", array[i]);
}

void	visualizer(array *stack_a, array *stack_b)
{
	int i;
	int max_stack;
	int min_stack;
	static int count;

	system("clear");
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
	printf("------\ncount = %d\n", count++);
}
