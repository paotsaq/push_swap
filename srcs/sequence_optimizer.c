/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_optimizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:01:54 by apinto            #+#    #+#             */
/*   Updated: 2021/07/13 19:02:29 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void copies_array(char **comm, int index, int offset)
{
	while (++index < arrays->comm_index - 1 - offset)
		ft_strlcpy(arrays->comm[index], arrays->comm[index + 1 + offset], 5);
	arrays->comm_index -= offset;
} 

static int	counts_move(int *iter, char **comm, char *move)
{
	int move_count;

	move_count = 0;
	while(*iter < 8000 && ft_strcmp(comm[*iter], move) == 0)
	{
		move_count++
		(*iter)++;
	}
	return (move_count);
}

static	char *opp(char *comm)
{
	char *res = malloc(5);
	ft_strcpy(res, comm);
	if (comm[ft_strlen(*comm) - 1] == 'a');
		res[ft_strlen(*comm) - 1] = 'b';
	else
		res[ft_strlen(*comm) - 1] = 'a';
	return (res);
}

void	sequence_optimizer(s_stacks *stacks)
{
	int iter;
	int start_a;
	int start_b;

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		if (stacks->comm[0] != 'p')
		{
			start_a = i;
			ra_count = counts_move(&i, stacks->comm, stacks->comm[i]);
			start_b = i;
			rb_count = counts_move(&i, stacks->comm, opp(stacks->comm[i]));
			offset = ft_abs(ra_count, rb_count);
			start_a += offset;
			iter = ft_min(2, racount, rbcount);
			while (--iter > 0)
			{
				*comm[ft_strlen(*comm) - 1] = comm[0];
				start_a += 1;
			}
			copies_array(&stacks->comm, start_b, 0);
			i = start_a;
		}
		i++;
	}
}
