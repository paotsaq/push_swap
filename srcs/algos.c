/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:35 by apinto            #+#    #+#             */
/*   Updated: 2021/06/07 11:11:55 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(array *stack)
{
	int i;

	i = -1;
	if (stack->count > 0)
		while (stack->stack[++i + 1])
			if (stack->stack[i] > (stack->stack[i + 1]))
				return (0);
	return (1);
}

/* determines whether to fetch top or bottom of stack
 * (rra or ra) for reducing of instructions
 * ra: shift up all elements
 * rra: shift down all elements
 * 1 is ra; 0 is rra */
static int determines_rotation(array *stack, int target)
{
	/* upper half */
	if (target < (stack->count / 2))
		return (1);
	/* lower half */
	else
		return (0);
}

/* util function that determines whether it is best 
 * to swap two elements in order to find a sort, 
 * or to just push to the other stack.
 * e.g: 2 1 3 is solved if swapped.
 * 1 says push
 * 0 says swap */
static	int	swap_or_push(array *stack_a, array *stack_b)
{
	int prev_checker;
	int new_checker;

	prev_checker = run_checks(stack_a);
	do_operations(stack_a, stack_b, "sa");
	new_checker = run_checks(stack_a);
	do_operations(stack_a, stack_b, "sa");
	if (prev_checker <= new_checker)
		return (1);
	else
		return (0);	
}

static	int get_target(array *stack)
{
	int iter;

	iter = 0;
	while (stack->largest_seq_buf[iter] != 0)
	{
		printf("seq: %d\n", stack->largest_seq_buf[iter]);
		iter++;
	}
	printf("target is %d\n", stack->stack[iter]);
	return iter;
}

/* this assumes run_checker has been launched prior,
 * because of reliance in largest_seq_buf */
void	sort_by_rotation(array *stack_a, array *stack_b)
{
	int target;

	target = get_target(stack_a);
	while (stack_a->stack[0] != target && target == -1)
		if (determines_rotation(stack_a, target) == 1)
			do_operations(stack_a, stack_b, "ra");
		else
			do_operations(stack_a, stack_b, "rra");
	if (swap_or_push(stack_a, stack_b) == 0)
		do_operations(stack_a, stack_b, "sa");
	else
		do_operations(stack_a, stack_b, "pa");
}

void	algo(array *stack_a, array *stack_b)
{
	int checker;

	checker = run_checks(stack_a);
	visualizer(stack_a, stack_b);
	printf("checker result is %d\n", checker);
	if (!is_sorted(stack_a))
		sort_by_rotation(stack_a, stack_b);
}
