/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:32:53 by apinto            #+#    #+#             */
/*   Updated: 2021/07/11 16:32:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initializes_array(list_of_arrays *arrays, int size)
{
	array *stack;

	stack = &arrays->arrays[arrays->count];
	stack->count = 0;
	stack->identity = arrays->count;
	stack->sorted = 0;
	stack->lis_index = -1;
	stack->size = size;
	stack->orientation = 0;
	stack->pending_lis = 0;
	arrays->count += 1;
}

static int	is_duplicate(int *stack, int len, char *string)
{
	int number;
	int iter;

	number = ft_atoi(string);
	iter = -1;
	while (++iter < len)
		if (stack[iter] == number)
			return (1);
	return (0);
}

static int	parsing_of_input(char **argv, list_of_arrays *arrays)
{
	int i;
	array *stack;

	stack = &arrays->arrays[0];
	stack->count = 0;
	i = -1;
	while (*++argv)
		if (ft_content_is_int(*argv) && !is_duplicate(stack->stack, stack->count++, *argv))
			stack->stack[++i] = atoi(*argv);
		else
		{
			printf("erro muito chato\nnão te esqueças de implementar frees!");
			return (-1);
		}
	return (1);
}

/*static  void	copy_all_back_because_im_lame(list_of_arrays *arrays, int index)
{
	while (++index < arrays->comm_index - 1)
		ft_strlcpy(arrays->comm[index], arrays->comm[index + 1], 4);
	--arrays->comm_index;
} */

int		main(int argc, char **argv)
{
	list_of_arrays arrays;
	int iter;

	if (argc == 1)
		return (0);
	arrays.count = 0;
	arrays.comm_index = -1;
	initializes_array(&arrays, 500);
	if (parsing_of_input(argv, &arrays) != -1)
		break_into_lis_algorithm(&arrays);
	else
		printf("I should free some stuff\n");
	iter = -1;
	// while(++iter < arrays.comm_index)
	// 	printf("%s\n", arrays.comm[iter]);
	return (0);
}
