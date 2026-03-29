#include "aicu.h"
#include "image.h"
#include <stdio.h>
#include <mlx.h>


int	main(int argc, char **argv)
{
	t_vector	vec;
	t_data		img;
	t_panel		panel;
	int			fd;
	void		*mlx;
	void		*mlx_win;
	int			screen_width;
	int			screen_height;
	unsigned int			diff;
	int			radius;
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
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	radius = screen_width * (3 / 4) / 16;
	mlx_win = mlx_new_window(mlx, screen_width, screen_height, "AICu");
	img.img = mlx_new_image(mlx, screen_width * (3 / 4), screen_height);
	panel.panel = mlx_new_image(mlx, screen_width * (1 / 4), screen_height);
	panel.addr = mlx_get_data_addr(panel.panel, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	for (size_t i = 0; i < vec.num_elements; i++)
	{
		diff = vec.max - vec.data[i];
		for (unsigned int j = 0; j < vec.data[i]; j++)
		{
			unsigned int	k = 0;
			int				offset;

			offset = 0;
			while (k < diff / 2)
				k++;
			if (diff % 2 != 0)
				offset = radius;
			draw_circle(&img, ((j + k) * radius * 2) + radius + 10 + offset, (i * radius * 2) + radius + 10, radius, 0x0000FF00, screen_width / 2, screen_height / 2);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	algo_loop(&vec);
	free(vec.data);
	
	return (0);
}