#include "image.h"

void    mlx_display(t_vector *vec)
{
    t_data		img;
	t_data		panel;   
    t_vars      vars;
	int			screen_width;
	int			screen_height;
    int			radius;
    int         slot_width;


    vars.mlx = mlx_init();
    mlx_get_screen_size(vars.mlx, &screen_width, &screen_height);
    
    img.width = (screen_width * 3) / 4;
    img.height = screen_height;
    slot_width = img.width / (vec->max + 1);

    panel.width = (screen_width * 1) / 4;
    panel.height = screen_height;
    radius = (slot_width * 8) / 20;
    int gap = (slot_width * 2) / 10;
    vars.win = mlx_new_window(vars.mlx, screen_width, screen_height, "AICu");
    img.img = mlx_new_image(vars.mlx, img.width, screen_height);
    panel.img = mlx_new_image(vars.mlx, panel.width, panel.height);
    panel.addr = mlx_get_data_addr(panel.img, &panel.bits_per_pixel, &panel.line_length, &panel.endian);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    for (size_t i = 0; i < vec->num_elements; i++)
    {
        unsigned int marble_count = vec->data[i];
        
        int row_width = (marble_count * (radius * 2)) + ((marble_count - 1) * gap);
        
        int start_x = (img.width - row_width) / 2;

        int start_y = (i + 1) * (radius * 2 + gap);

        for (unsigned int j = 0; j < marble_count; j++)
        {
            int cx = start_x + (j * (radius * 2 + gap)) + radius;
            int cy = start_y;

            draw_circle(&img, cx, cy, radius, 0x0000FF00, img.width, img.height); 
        }
    }
    
    draw_buttons(&panel, panel.width, panel.height);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_put_image_to_window(vars.mlx, vars.win, panel.img, img.width, 0);
    mlx_hook(vars.win, ON_DESTROY, 0, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);    
    mlx_loop(vars.mlx);

}