/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:57:03 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 03:57:21 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 2)
		return (0);
	initialize_stacks(&stacks);
	if (parsing_of_input(argv, &stacks) != -1)
		push_swap(&stacks);
	else
		write(1, "Error\n", 7);
	return (0);
}
