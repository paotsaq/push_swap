#include "../includes/push_swap.h"

/* updates the size array and handles
 * determining which is the largest sequence */
void	size_and_largest_sequence(chains *chain, int index, int size)
{
	chain->sizes[index] = size;
	if (size >= chain->largest_size)
	{
		chain->largest_active = chain->heads[index];
		chain->largest_size = size;
	}
}

void	copies_new_largest_list(int *old_list, int *new_list, int size)
{
	int i;
	i = -1;
	if (old_list != NULL && old_list != new_list)
		while (++i < size)
			new_list[i] = old_list[i];
}
