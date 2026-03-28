#include "vector.h"
#include "aicu.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vector	vec;
	int			fd;
	size_t	i;

	fd = 0;
	if (argc > 1)
	{
		if (argc > 2)
		{
			write(2, "Too much arguments!\n", 20);
			return (1);
		}
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "An error occurs with the file's path\n", 37);
			return (1);
		}
	}
	vector_init(&vec, 50);
	if (read_pro_max(&vec, fd) == -1)
	{
		printf("%i", vec.data[vec.num_elements - 1]);
		return (1);
	}
	i = 0;
	while (i < vec.num_elements)
	{
		printf("%u\n", vec.data[i]);
		i++;
	}
	free(vec.data);
	
	return (0);
}