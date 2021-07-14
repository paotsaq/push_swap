/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:11:52 by apinto            #+#    #+#             */
/*   Updated: 2021/05/26 10:23:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* places elem at the top of the stack
 * at a space left unfilled; */
void	place_at_top(t_array *stack, int elem)
{
	stack->stack[0] = elem;
}

/* places elem at the bottom of the stack
 * at a space left unfilled;
 * stack->count provides the information for the placement */
void	place_at_bottom(t_array *stack, int elem)
{
	stack->stack[*stack->count - 1] = elem;
}

/* shifs down all elements of a stack by one
 must ALWAYS precede another action to fill stack->stack[0]
 if last elem is out of stack bounds, fill pointer with elem*/
void	down_top(t_array *stack, int rotate, int *last, int *changed)
{
	int	i;

	if (*stack->count > 0)
	{
		i = *stack->count + 1;
		if (*stack->count + 1 > *stack->size || rotate)
		{
			*last = stack->stack[*stack->count - 1];
			*changed = 1;
		}
		while (--i != 0)
			stack->stack[i] = stack->stack[i - 1];
		stack->stack[0] = 0;
	}
}

/* shifs up all elements of a stack by one
 * returns the top element (which is now removed) *
 * the last element is now 0 */
int	remove_and_up_top(t_array *stack)
{
	int	i;
	int	top;

	if (*stack->count > 0)
	{
		top = stack->stack[0];
		i = -1;
		while (++i < *stack->count - 1)
			stack->stack[i] = stack->stack[i + 1];
		stack->stack[*stack->count - 1] = 0;
		return (top);
	}
	return (-1);
}
