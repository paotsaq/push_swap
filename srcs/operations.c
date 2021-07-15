/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:31:06 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 03:32:15 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* shift all elements up;
 * fills last spot with previous top element */
void	rotate(t_array *stack)
{
	if (*stack->count > 1)
		place_at_bottom(stack, remove_and_up_top(stack));
}

/* shift all elements down;
 * fills first spot with previous last element */
void	reverse_rotate(t_array *stack)
{
	int tmp;
	int changed;

	tmp = 0;
	changed = 0;
	if (*stack->count > 1)
	{
		down_top(stack, 1, &tmp, &changed);
		if (changed)
			place_at_top(stack, tmp);
	}
}

/* swap the first two elements at the top of a stack */
void	swap(t_array *stack)
{
	int tmp;

	if (*stack->count > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

/* takes the first element of gives
 * puts it on top of receives*/
void	push(t_array *gives, t_array *receives)
{
	if (*gives->count > 0)
	{
		down_top(receives, 0, NULL, NULL);
		place_at_top(receives, remove_and_up_top(gives));
		(*gives->count)--;
		(*receives->count)++;
	}
}
