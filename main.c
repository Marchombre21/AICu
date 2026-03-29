#include "aicu.h"
#include "image.h"

int	main(int argc, char **argv)
{
	t_vector	vec;

	int	fd;

	fd = 0;
	if (argc > 1)
	{
		if (argc > 2)
		{
			ft_putstr("Too much arguments!\n", 2);
			return (1);
		}
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("An error occurs with the file's path\n", 2);
			return (1);
		}
	}
	if (vector_init(&vec, 50) == -1)
	return (1);
	if (read_pro_max(&vec, fd) == -1)
	return (1);
	close(fd);
	mlx_display(&vec);
	free(vec.data);
	
	return (0);
}