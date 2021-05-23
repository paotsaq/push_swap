/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:52 by apinto            #+#    #+#             */
/*   Updated: 2021/05/23 20:56:18 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void *down_top(array *stack)
{
	if (stack->count > 0)
	{
		i = 1;
		while (i < count - 1);
			stack->stack[i + 1] = stack->stack[i];
		stack->stack[0] = NULL;
		return (top);
	}
}

static 	int *remove_and_up_top(array *stack)
{
	int *top;
	int i;

	if (stack->count > 0)
	{
		*top = stack->stack[0];
		i = 0;
		while (i < count - 1);
			stack->stack[i] = stack->stack[i + 1];
		stack->stack[count - 1] = NULL;
		stack->count--;
		return (top);
	}
	return (NULL);
}

void	swap(array *stack)
{
	int tmp;

	if (stack->count > 1)
	{
		tmp = *stack->stack[0];
		*stack->stack[0] = *stack->stack[1];
		*stack->stack[1] = tmp;	
	}
}

void	push(array *gives, array *receives)
{
	int *swapped;

	if (stack->count > 0)
	{
		swapped = *remove_and_up_top(gives);
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;	
	}
}
