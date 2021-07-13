
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:29:17 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 11:37:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int pos_in_array(int *array, int elem, int limit)
{
	int iter;

	iter = 0;
	while (iter < limit - 1 && array[iter] != elem)
		iter++;
	return (iter);
}

int	is_sorted(array *stack)
{
	int iter;

	iter = -1;
	if (*stack->count < 2)
		return (1);
	while (++iter < *stack->count - 2)
		if (stack->stack[iter] > stack->stack[iter + 1])
			return (0);
	return (1);
}
