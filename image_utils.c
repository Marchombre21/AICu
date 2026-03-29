
#include "image.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int width, int height)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= width || y >= height)
        return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_data *img, int x_center, int y_center, int radius, int color, int width, int height)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		my_mlx_pixel_put(img, x_center + x, y_center + y, color, width, height);
		my_mlx_pixel_put(img, x_center + y, y_center + x, color, width, height);
		my_mlx_pixel_put(img, x_center - y, y_center + x, color, width, height);
		my_mlx_pixel_put(img, x_center - x, y_center + y, color, width, height);
		my_mlx_pixel_put(img, x_center - x, y_center - y, color, width, height);
		my_mlx_pixel_put(img, x_center - y, y_center - x, color, width, height);
		my_mlx_pixel_put(img, x_center + y, y_center - x, color, width, height);
		my_mlx_pixel_put(img, x_center + x, y_center - y, color, width, height);

		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

void	draw_buttons(t_panel panel, int width, int height)
{
	int	offset_x;
	int	offset_y;
	int	x;
	int	y;
	int	button_height;

	offset_x = width * 0.1;
	offset_y = (height / 3) / 2;
	butt
	for (x = 0; x < width - offset_x; x++)
	{
		for (y = 0; y < )

	}

}