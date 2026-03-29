#include "aicu.h"
#include "image.h"
#include <stdio.h>
#include <mlx.h>


int	main(int argc, char **argv)
{
	t_vector	vec;
	t_data		img;
	int			fd;
	void		*mlx;
	void		*mlx_win;
	int			screen_width;
	int			screen_height;
	// int			x;
	// int			y;

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
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	mlx_win = mlx_new_window(mlx, screen_width / 2, screen_height / 2, "AICu");
	img.img = mlx_new_image(mlx, screen_width / 2, screen_height / 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// y = 5;
	// while (y < 55)
	// {
	// 	x = 5;
	// 	while (x < 55)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	y++;
	// }
	if (vector_init(&vec, 50) == -1)
	return (1);
	if (read_pro_max(&vec, fd) == -1)
	return (1);
	close(fd);
	img.marbles = malloc(sizeof(int) * vec.num_elements);
	if (!img.marbles)
		return (1);
	for (int i = vec.num_elements; i > 0; i--)
	{
		img.marbles[i] = malloc(sizeof(int) * vec.data[i - 1]);
		if (!img.marbles[i])
		{
			
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	algo_loop(&vec);
	free(vec.data);
	
	return (0);
}