#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	array *stack_a;
	array *stack_b;

	if (argc == 1)
		return (1);
	else
	{
		stack_a = calloc(argc - 1, sizeof(array));
		stack_b = calloc(argc - 1, sizeof(array));
		if (!(stack_a && stack_b))
			return (-1);
		while (*++argv)
			if (ft_content_is_int(*argv))
				*(stack_a->stack)++ = atoi(*argv);

		printf("size of array is %lu\n", sizeof(beg_numbers));
	}
}
