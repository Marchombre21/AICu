#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_panel {
	void	*panel;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_panel;

// typedef struct	s_marble {
// 	void	*marble;
// }				t_marble;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int width, int height);
void draw_circle(t_data *img, int x_center, int y_center, int radius, int color, int width, int height);

#endif