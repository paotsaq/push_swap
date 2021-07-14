/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_optimizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:01:54 by apinto            #+#    #+#             */
/*   Updated: 2021/07/14 18:12:33 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	next_different_command_index(t_stacks *stacks, int iter, char *move)
{
	while (iter < stacks->comm_index
		&& (ft_strcmp(stacks->comm[iter], move) == 0
			|| ft_strcmp(stacks->comm[iter], "None") == 0))
		iter++;
	return (iter);
}

static void	opposite_cmd(t_stacks *stacks, char *comm)
{
	ft_strlcpy(stacks->opp_move, comm, 5);
	if (comm[ft_strlen(comm) - 1] == 'a')
		stacks->opp_move[ft_strlen(comm) - 1] = 'b';
	else
		stacks->opp_move[ft_strlen(comm) - 1] = 'a';
}

static int	command_can_be_optimized(char *comm)
{
	return (comm[0] != 'p' && comm[0] != 'N');
}

static void	double_stack_command(char *comm)
{
	comm[ft_strlen(comm) - 1] = 'r';
}

void	sequence_optimizer(t_stacks *stacks)
{
	int		iter;
	int		next_cmd_index;
	char	*move;

	iter = -1;
	while (++iter < stacks->comm_index)
	{
		if (command_can_be_optimized(stacks->comm[iter]))
		{
			move = stacks->comm[iter];
			next_cmd_index = next_different_command_index(stacks, iter, move);
			opposite_cmd(stacks, move);
			if (ft_strcmp(stacks->comm[next_cmd_index], stacks->opp_move) == 0)
			{
				double_stack_command(stacks->comm[iter]);
				ft_strlcpy(stacks->comm[next_cmd_index], "None", 5);
			}
		}
	}
}
