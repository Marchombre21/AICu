
#include "image.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int width, int height)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= width || y >= height)
        return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static void draw_rectangle(t_data *img, int x_start, int y_start, int rect_width, int rect_height, int color, int max_width, int max_height)
{
    int x;
    int y;

    y = 0;
    while (y < rect_height)
    {
        x = 0;
        while (x < rect_width)
        {
            my_mlx_pixel_put(img, x_start + x, y_start + y, color, max_width, max_height);
            x++;
        }
        y++;
    }
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

static void draw_thick_line(t_data *panel_img, int center_x, int center_y, int panel_width, int panel_height)
{
    int line_w = 8; 
    int line_h = 40;

    draw_rectangle(panel_img, center_x - (line_w / 2), center_y - (line_h / 2), 
                   line_w, line_h, 0x00FFFFFF, panel_width, panel_height);
}

static void draw_lines_in_button(t_data *panel_img, int center_x, int center_y, int count, int panel_width, int panel_height)
{
    int spacing = 20;
    
    int start_x = center_x - ((count - 1) * spacing) / 2;

    for (int i = 0; i < count; i++)
    {
        draw_thick_line(panel_img, start_x + (i * spacing), center_y, panel_width, panel_height);
    }
}



void draw_buttons(t_data *panel_img, int panel_width, int panel_height)
{
    int offset_x;
    int button_width;
    int button_height;
    int offset_y;
    int button_gap = 20; // Espace entre les boutons

    offset_x = panel_width / 10; 
    button_width = panel_width - (offset_x * 2); 
    button_height = panel_height / 8;
    offset_y = panel_height / 6;

    for (int i = 0; i < 3; i++)
    {
        int current_y = offset_y + (i * (button_height + button_gap));
        
        int center_x = offset_x + (button_width / 2);
        int center_y = current_y + (button_height / 2);

        draw_rectangle(panel_img, offset_x, current_y, button_width, button_height, 0x00222222, panel_width, panel_height);

        draw_lines_in_button(panel_img, center_x, center_y, i + 1, panel_width, panel_height);
    }
}