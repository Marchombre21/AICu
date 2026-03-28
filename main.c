#include "vector.h"
#include "aicu.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vector	vec;
	// size_t	i;

	if (argc > 1)
	{
		
	}
	vector_init(&vec, 50);
	if (read_pro_max(&vec) == -1)
	{
		printf("%i", vec.data[vec.num_elements - 1]);
		return (1);
	}
	// i = 0;
	// while (i < vec.num_elements)
	// {
	// 	printf("%u\n", vec.data[i]);
	// 	i++;
	// }
	free(vec.data);
	
	return (0);
}