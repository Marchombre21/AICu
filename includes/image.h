#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	void	***marbles;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif