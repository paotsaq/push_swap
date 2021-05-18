#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int *numbers;
	int *beg_numbers;

	if (argc == 1)
		return (1);
	else
	{
		numbers = calloc(argc - 1, sizeof(int));
		if (!numbers)
			return (-1);
		beg_numbers = numbers;
		while (*++argv)
			if (ft_content_is_int(*argv))
				*numbers++ = atoi(*argv);
		printf("size of array is %lu\n", sizeof(beg_numbers));
	}
}
