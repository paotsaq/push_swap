/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:31:04 by apinto            #+#    #+#             */
/*   Updated: 2021/07/12 07:47:17 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	initialize_best_moves(best_moves *list)
{
	list->minimum_cost = INT_MAX;
	list->minimum_cost_index = 0;
	list->index = 0;
}

static void	fill_distances(best_moves *list)
{
	move_info *move;

	move = &list->moves[list->index];
	move->same = 0;
	if (move->a_top < move->a_bot)
		ft_strlcpy(move->dir_a, "r", 5);
	else
		ft_strlcpy(move->dir_a, "revr", 5);
	if (move->b_top < move->b_bot)
		ft_strlcpy(move->dir_b, "r", 5);
	else
		ft_strlcpy(move->dir_b, "revr", 5);
	if (ft_strncmp(move->dir_a, move->dir_b, 5) == 0)
	{
		if (ft_strncmp(move->dir_a, "r", 5) == 0)
			move->min = ft_max(2, move->a_top, move->b_top);
		else
			move->min = ft_max(2, move->a_bot, move->b_bot);
		move->same = 1;
	}
	else if (ft_strncmp(move->dir_a, "r", 5) == 0)
		move->min = move->a_top + move->b_bot;
	else
		move->min = move->a_bot + move->b_top;
}

static void	gets_distances(best_moves *list, array *stack_a, array *stack_b)
{
	int e_pos;
	int l_pos;

	e_pos = -1;
	while (++e_pos < stack_b->count)
	{
		l_pos = get_corresponding_lis_position(stack_a, stack_b->stack[e_pos]);
		if (l_pos == stack_a->lis_size - 1 && stack_b->stack[e_pos] > stack_a->lis[stack_a->lis_size - 1])
			l_pos = 0;
		list->moves[list->index].a_elem = stack_a->lis[l_pos];
		list->moves[list->index].b_elem = stack_b->stack[e_pos];
		list->moves[list->index].b_top = e_pos;
		l_pos = get_elem_position_in_stack(stack_a, stack_a->lis[l_pos]);
		list->moves[list->index].a_top = l_pos;
		list->moves[list->index].b_bot = (stack_b->count - e_pos);
		list->moves[list->index].a_bot = (stack_a->count - l_pos - 1);
		fill_distances(list);
		if (list->moves[list->index].min < list->minimum_cost)
		{
			list->minimum_cost = list->moves[list->index].min;
			list->elem = stack_b->stack[e_pos];
			list->minimum_cost_index = e_pos;
		}
		list->index++;
	}
}

static void	make_move(best_moves *list, list_of_arrays *arrays)
{
	move_info *move;
	array *stack_a;
	array *stack_b;

	stack_a = &arrays->arrays[arrays->count - 2];
	stack_b = &arrays->arrays[arrays->count - 1];
	move = &list->moves[list->minimum_cost_index];
	while (stack_a->stack[0] != move->a_elem)
		do_operations(arrays, move->dir_a, 0);
	while (stack_b->stack[0] != move->b_elem)
		do_operations(arrays, move->dir_b, 1);
	do_operations(arrays, "p", 1);
}

void best_move_interface(list_of_arrays *arrays)
{
	best_moves list;
	array *stack_a;
	array *stack_b;

	stack_a = &arrays->arrays[arrays->count - 2];
	stack_b = &arrays->arrays[arrays->count - 1];
	initialize_best_moves(&list);
	gets_distances(&list, stack_a, stack_b);
	make_move(&list, arrays);
}
