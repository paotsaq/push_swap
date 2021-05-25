#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	array *stack_a;
	array *stack_b;
	int *begg_stack_a;

	if (argc == 1)
		return (1);
	else
	{
		stack_a = calloc(1, sizeof(array));
		stack_b = calloc(1, sizeof(array));
		if (!(stack_a && stack_b))
			return (-1);
		stack_a->stack = calloc(argc - 1, sizeof(int *));
		stack_b->stack = calloc(argc - 1, sizeof(int *));
		if (!(stack_a->stack && stack_b->stack))
			return (-1);
		begg_stack_a = stack_a->stack;
		while (*++argv)
			if (ft_content_is_int(*argv))
				*(stack_a->stack)++ = atoi(*argv);
		stack_a->stack = begg_stack_a;
		stack_a->count = argc - 1;
		stack_a->size = argc - 1;

		operations(stack_a, stack_b);
	}
}
