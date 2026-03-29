#ifndef IMAGE_H
# define IMAGE_H

#include "vector.h"
#include <mlx.h>
#include <stdlib.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;


typedef enum e_keys {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} 			t_keys;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void draw_circle(t_data *img, int x_center, int y_center, int radius, int color, int width, int height);
void    mlx_display(t_vector *vec);
void draw_buttons(t_data *panel_img, int panel_width, int panel_height);
int	close_win(t_vars *vars);
int	key_hook(int keycode, t_vars *vars);

#endif