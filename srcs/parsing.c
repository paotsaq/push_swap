/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:24:23 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 03:24:38 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duplicate(int *stack, int len, char *string)
{
	int	number;
	int	iter;

	number = ft_atoi(string);
	iter = -1;
	while (++iter < len)
		if (stack[iter] == number)
			return (1);
	return (0);
}

int	parsing_of_input(char **argv, t_stacks *stacks)
{
	int		i;

	stacks->a_count = 0;
	i = -1;
	while (*++argv)
		if (ft_content_is_int(*argv)
			&& !is_duplicate(stacks->a, stacks->a_count++, *argv))
			stacks->a[++i] = atoi(*argv);
	else
		return (-1);
	stacks->sorted_size = i + 1;
	return (1);
}
