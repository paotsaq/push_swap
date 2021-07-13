/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:31:04 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 07:29:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int get_corresponding_lis_position(s_stacks *stacks, int elem)
{
	int iter;

	iter = 0;
	while (iter < stacks->lis_size - 1 && stacks->lis[iter] < elem)
		iter++;
	return (iter);
}

static int get_elem_position_in_stack(s_stacks *stacks, int elem)
{
	int iter;

	iter = 0;
	while (iter < stacks->lis_size - 1 && stacks->a[iter] != elem)
		iter++;
	return (iter);
}

static void	initialize_best_moves(best_moves *list)
{
	list->minimum_cost = INT_MAX;
	list->minimum_cost_index = 0;
	list->index = -1;
}

static void	fill_distances(best_moves *list)
{
	move_info	*move;

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

static void	gets_distances(best_moves *list, s_stacks *stacks, int e_pos)
{
	int l_pos;

	l_pos = get_corresponding_lis_position(stacks, stacks->b[e_pos]);
	if (l_pos == stacks->lis_size - 1
		&& stacks->b[e_pos] > stacks->lis[stacks->lis_size - 1])
		l_pos = 0;
	list->moves[list->index].a_elem = stacks->lis[l_pos];
	list->moves[list->index].b_elem = stacks->b[e_pos];
	list->moves[list->index].b_top = e_pos;
	l_pos = get_elem_position_in_stack(stacks, stacks->lis[l_pos]);
	list->moves[list->index].a_top = l_pos;
	list->moves[list->index].b_bot = (stacks->b_count - e_pos);
	list->moves[list->index].a_bot = (stacks->a_count - l_pos - 1);
	fill_distances(list);
	if (list->moves[list->index].min < list->minimum_cost)
	{
		list->minimum_cost = list->moves[list->index].min;
		list->elem = stacks->b[e_pos];
		list->minimum_cost_index = e_pos;
	}
}

static void	make_move(best_moves *list, s_stacks *stacks)
{
	move_info	*move;

	move = &list->moves[list->minimum_cost_index];
	while (stacks->a[0] != move->a_elem)
		do_operations(stacks, move->dir_a, 0);
	while (stacks->b[0] != move->b_elem)
		do_operations(stacks, move->dir_b, 1);
	do_operations(stacks, "p", 1);
}

void	best_move_interface(s_stacks *stacks)
{
	best_moves	list;
	int		e_pos;

	initialize_best_moves(&list);
	e_pos = -1;
	while (++e_pos < stacks->b_count)
	{
	   	list.index++;
		gets_distances(&list, stacks, e_pos);
	}
	make_move(&list, stacks);
}
