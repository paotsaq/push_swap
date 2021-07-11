/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/11 13:13:01 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_elem_from_other_stack(list_of_arrays *arrays, int elem)
{
	int left_range;
	int right_range;
	int amount;
	array *stack;

	left_range = right_range = 0;
	stack = &arrays->arrays[arrays->count - 1];
	amount = 0;
	while (stack->stack[0] != elem)
	{
		amount++;
		do_operations(arrays, "r", 1);
	}
	do_operations(arrays, "p", 1);
	while (amount-- != 0)
		do_operations(arrays, "revr", 1);
}

/* static void	operate_the_stack_strategically(list_of_arrays *arrays, int elem, int median, int less)
{
	array *stack;
	array *other_stack;
	int head;
	int next;
	int start;
	int prev;
	int end;
	int circled;

	stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	median++;
	less++;
	head = stack->stack[0];
	next = stack->stack[1];
	prev = stack->lis[(stack->lis_index + 2 + stack->lis_size) % stack->lis_size];
	start = stack->start_of_lis_range;
	end = stack->end_of_lis_range;
	circled = stack->lis_circled;
	if (next == start && (head > start && head < prev && !circled))
	{
		do_operations(arrays, "s", 0);
		update_lis_with_elem(stack, elem);
	}
	else
		do_operations(arrays, "p", 0);
} */

void		print_lis_center(array *stack)
{
	printf("left: %d; center: %d; right: %d\n", stack->lis_left, stack->lis_center, stack->lis_right);
}

void		break_into_lis_algorithm(list_of_arrays *arrays)
{
	array *this_stack;
	array *other_stack;
	int target;
	char direction[5];

	initializes_array(arrays, 500);
	this_stack = &arrays->arrays[arrays->count - 2];
	find_median_and_sort_array(arrays);
	other_stack = &arrays->arrays[arrays->count - 1];
	find_lis(this_stack);
	while (!(this_stack->count == this_stack->lis_size))
		if (element_is_in_lis(this_stack, this_stack->stack[0]))
			do_operations(arrays, "r", 0);
		else
			do_operations(arrays, "p", 0);
	while (!(this_stack->count == arrays->sorted_size))
	{
		best_move_interface(arrays);
		update_lis_with_elem(this_stack, this_stack->stack[0]);
	}
	target = get_elem_position_in_stack(this_stack, this_stack->lis[0]);
	if (target < this_stack->count / 2)
		ft_strlcpy(direction, "r", 5);
	else
		ft_strlcpy(direction, "revr", 5);
	while (!(this_stack->stack[0] == this_stack->lis[0]))
		do_operations(arrays, direction, 0);
}
