/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/10 19:22:25 by apinto           ###   ########.fr       */
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

static void	operate_the_stack_strategically(list_of_arrays *arrays, int elem, int median, int less)
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
	/* LIS can be extended with a swap, in place. */
	if (next == start && (head > start && head < prev && !circled))
	{
		do_operations(arrays, "s", 0);
		update_lis_with_elem(stack, elem);
	}
	/* LIS is consecutive, and there are elements in between! shove everything. */
	else 
		do_operations(arrays, "p", 0);
}
void		print_lis_center(array *stack)
{
	printf("left: %d; center: %d; right: %d\n", stack->lis_left, stack->lis_center, stack->lis_right);
}

void		break_into_lis_algorithm(list_of_arrays *arrays)
{
	int elem;
	int lis_elem_index;
	int head_of_stack;
	array *this_stack;
	array *other_stack;
	int direction;
	int median;

	initializes_array(arrays, 500);
	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	find_lis(this_stack);
	// print_lis(this_stack);
	head_of_stack = this_stack->lis[0];
	median = find_median_and_sort_array(arrays);
	direction = 0;
	get_first_lis_center(this_stack);
	print_lis_center(this_stack);
	while (!(this_stack->sorted && this_stack->count == arrays->sorted_size))
	{
		visualizer(&arrays->arrays[arrays->count - 2], &arrays->arrays[arrays->count - 1]);
		elem = this_stack->stack[0];
		if (element_lis_index(this_stack, elem, &lis_elem_index))
		{
			get_lis_center(this_stack, lis_elem_index);
			print_lis_center(this_stack);
			/*while(any_in_lis_range(arrays, &elem))
			{
				get_elem_from_other_stack(arrays, elem);
				update_lis_with_elem(this_stack, elem);
				update_lis_interval(this_stack);
			}*/
			do_operations(arrays, "revr", 0);
		}
		else
			operate_the_stack_strategically(arrays, elem, median, direction);
	}
}
