/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/03 07:52:22 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	operate_the_stack_strategically(list_of_arrays *arrays, int elem, int median)
{
	array *stack;
	array *other_stack;
	int head;
	int next;
	int start;
	int end;
	int circled;

	stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	head = stack->stack[0];
	next = stack->stack[1];
	start = stack->start_of_lis_range;
	end = stack->end_of_lis_range;
	circled = stack->lis_circled;
	/* LIS can be extended with a swap, in place. */
	if ((next == start && head > start && ((head < end && !circled) || (head > end && circled))) ||
		(stack->size >= 2 && next == stack->lis[stack->lis_size - 1] && head > next) ||
		(head == end && next < head && next > start))
	{
		do_operations(arrays, "s", 0);
		update_lis_with_elem(stack, elem);
	}
	/* current head belongs in the next LIS range; there are also other elements in between */
	else if (head > start && ((head < end && !circled) || (head > end && circled)))
	{
		do_operations(arrays, "p", 0);
		do_operations(arrays, "r", 1);
		other_stack->pending_lis++;
	}
	/* if lis_shoved, check if element */
	else if (lis_shoved && head > start && head < end)
	{
		do_operations(arrays, "r", 1);
		other_stack->pending_lis++;
	}
	else if (elem < median)
		do_operations(arrays, "r", 0);
	else
		do_operations(arrays, "p", 0);
}

/* ⚠️  should assume end_of_list is head of stack
 * checks whether there are eligible elements for CURRENT stack
 * after end_of_stack; if so, return 1, to promote shoving of end_of_stack */
static int look_ahead_of_lis(list_of_arrays *arrays)
{
	array *this_stack;
	array *other_stack;
	int *current_elem;

	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	current_elem = this_stack->stack[0];

	while(*current_elem != this_stack->stack[(this_stack->current_range + 1) % this_stack->lis_size])
		if (*current_elem > this_stack->start_of_lis_range && *current_elem <  this_stack->end_of_lis_range)
		{
			this_stack->lis_shoved = 1;
			return (1);
		}
		else
			current_elem = (current_elem + 1) % this_stack->count;
	return (0);
}

static void push_pending_lis(list_of_arrays *arrays)
{
	int elem_to_lis;
	array *this_stack;
	array *other_stack;

	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	printf("THIS MUST BE OPTIMIZED REEE 🧚‍♀️");
	do_operations(arrays, "r", 0);
	do_operations(arrays, "revr", 1);
	elem_to_lis = other_stack->stack[0];
	do_operations(arrays, "p", 1);
	update_lis_with_elem(this_stack, elem_to_lis);
}

void		break_into_lis_algorithm(list_of_arrays *arrays)
{
	int elem;
	int median;
	int head_of_stack;
	array *this_stack;
	array *other_stack;

	initializes_array(arrays, 500);
	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	find_lis(this_stack);
	median = find_median(this_stack);
	print_lis(this_stack);
	head_of_stack = this_stack->lis[0];
	while (!stack_is_sorted(this_stack) || (head_of_stack != this_stack->lis[0] && other_stack->count == 0))
	{
		elem = this_stack->stack[0];
		if (element_is_in_lis(this_stack, elem, 0))
		{
			if (look_ahead_of_lis(arrays) && lis_shoved)
			{
				do_operations(arrays, "p", 0);
				do_operations(arrays, "revr", 1);
				continue;
			}
			if (this_stack->stack[1] < elem && this_stack->stack[1] > this_stack->start_of_lis_range)
				operate_the_stack_strategically(arrays, this_stack->stack[1], median);
			if (other_stack->pending_lis > 0)
			{
				if (other_stack->pending_lis > 1)
					printf("BEHOLD!! ✨\n");
				while (other_stack->pending_lis-- != 0)
					push_pending_lis(arrays);
			}
			if (lis_shoved
			do_operations(arrays, "r", 0);
			update_lis_interval(this_stack, 0);
		}
		else
			operate_the_stack_strategically(arrays, elem, median);
	}
	printf("median is %d\n", median);
	printf("new lis w/ size %d\n", this_stack->lis_size);
	print_lis(this_stack);
}
