/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:32:39 by apinto            #+#    #+#             */
/*   Updated: 2021/07/04 17:49:43 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_elem_from_other_stack(list_of_arrays *arrays, int elem)
{
	int amount;
	array *stack;

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
	/* if lis_shoved, get the previous lis element back from the other stack
	else if (stack->lis_shoved && head > start && head < end)
	{
		do_operations(arrays, "r", 1);
		do_operations(arrays, "p", 1);
	}
	*/
	else if (elem > median)
		do_operations(arrays, "r", 0);
	else
		do_operations(arrays, "p", 0);
	/* this is going to be pushed. check if the next elem is also eligible to be pushed and, if so, whether they should be swapped? */
}

/* ⚠️  should assume end_of_list is head of stack
 * checks whether there are eligible elements for CURRENT stack
 * after end_of_stack; if so, return 1, to promote shoving of end_of_stack */
static int look_ahead_of_lis(list_of_arrays *arrays)
{
	array *this_stack;
	array *other_stack;
	int iter;

	this_stack = &arrays->arrays[arrays->count - 2];
	other_stack = &arrays->arrays[arrays->count - 1];
	iter = -1;
	while(this_stack->stack[++iter] != this_stack->lis[(this_stack->current_range + 1) % this_stack->lis_size])
		if (this_stack->stack[iter] > this_stack->start_of_lis_range && this_stack->stack[iter] < this_stack->end_of_lis_range)
		{
			this_stack->lis_shoved = 1;
			return (1);
		}
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
			/* LIS is consecutive! start looking for next LIS 
			if (elem + 1 == this_stack->lis[this_stack->current_range])
			{
				do_operations(arrays, "r", 0);
				update_lis_interval(this_stack, 0);
				continue;
			}*/
			/* elementary optimization: LIS can be extended with a swap,
			 * but LOOK_AHEAD would also be triggered.
			 * Make look ahead ignore this particular case, where swap is more efficient than pushing?
			 * LIS RANGE SHOULD BE UPDATED */
			if (this_stack->stack[1] < elem && this_stack->stack[1] > this_stack->start_of_lis_range)
			{
				operate_the_stack_strategically(arrays, this_stack->stack[1], median);
				update_lis_interval(this_stack, 0);
				continue;
			}
			if (look_ahead_of_lis(arrays) && this_stack->lis_shoved)
			{
				do_operations(arrays, "p", 0);
				do_operations(arrays, "revr", 1);
				continue;
			}
			if (other_stack->pending_lis > 0)
			{
				if (other_stack->pending_lis > 1)
					printf("BEHOLD!! ✨\n");
				while (other_stack->pending_lis-- != 0)
					push_pending_lis(arrays);
			}
			if (this_stack->lis_shoved)
			{
				do_operations(arrays, "r", 1);
				do_operations(arrays, "p", 1);
			}
			do_operations(arrays, "r", 0);
			update_lis_interval(this_stack, 0);
		}
		else
			operate_the_stack_strategically(arrays, elem, median);
		/* ⚠️  still unreliable! these must be sorted when 
		 * getting eligible elements from the other stack. */
		while(any_in_lis_range(arrays, &elem))
		{
			get_elem_from_other_stack(arrays, elem);
			do_operations(arrays, "r", 0);
		}
	}
	printf("new lis w/ size %d\n", this_stack->lis_size);
	print_lis(this_stack);
}
