#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct array {
	int *stack;
	int	count;
	int	size;
} array;

int		main(int argc, char **argv);
void	operations(array *stack_a, array *stack_b);
void	swap(array *stack);
void	push(array *gives, array *receives);
