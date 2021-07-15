/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:24:23 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 13:20:20 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parsing_of_checker_input(char *str, t_stacks *stacks)
{
	if (ft_content_is_int(str)
		&& !is_duplicate(stacks->a, stacks->a_count++, str))
		stacks->a[stacks->a_count] = atoi(str);
	else
		return (-1);
	stacks->sorted_size += 1;
	return (1);
}
