/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_optimizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:01:54 by apinto            #+#    #+#             */
/*   Updated: 2021/07/14 07:40:33 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <string.h>

static void copies_array(s_stacks *stacks, int index, int offset)
{
	int comm_index;

	comm_index = stacks->comm_index;
	while (index < comm_index - 1 - offset)
	{
		ft_strlcpy(stacks->comm[index], stacks->comm[index + offset], 5);
		index++;
	}
	stacks->comm_index -= offset;
}

static int	counts_move(s_stacks *stacks, int *iter, char *move)
{
	int move_count;

	move_count = 0;
	while(*iter < 8000 && ft_strcmp(stacks->comm[*iter], move) == 0)
	{
		move_count++;
		(*iter) += 1;
	}
	return (move_count);
}

static	char *opp(char *comm)
{
	char *res = malloc(5);
	strcpy(res, comm);
	if (comm[ft_strlen(comm) - 1] == 'a')
		res[ft_strlen(comm) - 1] = 'b';
	else
		res[ft_strlen(comm) - 1] = 'a';
	return (res);
}

void	sequence_optimizer(s_stacks *stacks)
{
	int iter;
	int start_a;
	int start_b;
	int ra_count;
	int rb_count;
	int excess;
	int to_swap;

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		if (stacks->comm[iter][0] != 'p')
		{
			start_a = iter;
			ra_count = counts_move(stacks, &iter, stacks->comm[iter]);
			start_b = iter;
			rb_count = counts_move(stacks, &iter, opp(stacks->comm[start_a]));
			if (rb_count > 0)
			{
				excess = ft_abs(ra_count - rb_count);
				start_a += excess;
				to_swap = ft_min(2, ra_count, rb_count);
				while (to_swap-- > 0)
				{
					stacks->comm[start_a][ft_strlen(stacks->comm[start_a]) - 1] = stacks->comm[start_a][0];
					start_a += 1;
				}
				copies_array(stacks, start_a, ft_min(2, ra_count, rb_count));
			}
			iter = start_a;
		}
	}
}
