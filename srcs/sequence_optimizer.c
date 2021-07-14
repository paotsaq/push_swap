/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_optimizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:01:54 by apinto            #+#    #+#             */
/*   Updated: 2021/07/14 16:08:23 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <string.h>


static int	next_different_command_index(s_stacks *stacks, int iter, char *move)
{
	/* change this iter < 8000 */
	while(iter < 8000
		   	&& (ft_strcmp(stacks->comm[iter], move) == 0
		   	|| ft_strcmp(stacks->comm[iter], "None") == 0))
		iter++;
	return (iter);
}

/* beware this leak! */
static	char *opposite_cmd(char *comm)
{
	char *res = malloc(5);
	strcpy(res, comm);
	if (comm[ft_strlen(comm) - 1] == 'a')
		res[ft_strlen(comm) - 1] = 'b';
	else
		res[ft_strlen(comm) - 1] = 'a';
	return (res);
}

static int	command_can_be_optimized(char *comm)
{
	return (comm[0] != 'p' && comm[0] != 'N');
}

static void	double_stack_command(char *comm)
{
	comm[ft_strlen(comm) - 1] = 'r';
}

void	sequence_optimizer(s_stacks *stacks)
{
	int iter;
	int next_cmd_index;
	char *move;

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		if (command_can_be_optimized(stacks->comm[iter]))
		{
			move = stacks->comm[iter];
			next_cmd_index = next_different_command_index(stacks, iter, move);
			if (ft_strcmp(stacks->comm[next_cmd_index], opposite_cmd(move)) == 0)
			{
				double_stack_command(stacks->comm[iter]);
				strlcpy(stacks->comm[next_cmd_index], "None", 5);
			}
		}
	}
}
